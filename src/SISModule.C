
/******************************************************************************
 *   SIS module threshold modifier                                            *
 *                                                                            *
 *   29.01.2020 Juelich                                                       *
 *                                                                            *
 *   i.keshelashvili@fz-juelich.de                                            *
 *                                                                            *
 *****************************************************************************/

#include "SISModule.h"

ClassImp(SISModule)

//-----------------------------------------------------------------------------
//
SISModule::SISModule(const TGWindow * p, const char * title, UInt_t opt, 
                     GContext_t norm, FontStruct_t font, Pixel_t back) :
  TGGroupFrame(p, title, opt, norm, font, back)
{
    fModuleName = title;
    
    // over channels
    for(int i=0; i<kMaxCh; i++) {

        fChLbl[i] = new TGLabel(this, Form("Ch:%2i", i ) );
        this->AddFrame(fChLbl[i], new TGLayoutHints( kLHintsBottom | kLHintsLeft | kLHintsExpandX | kLHintsCenterY, 2, 2, 2, 2));

        ch[i] = new TGNumberEntry(this,  50, 9, 999, 
                                    TGNumberFormat::kNESInteger,
                                    TGNumberFormat::kNEANonNegative,
                                    TGNumberFormat::kNELLimitMinMax,
                                    0, 16384);
        // ch[i]->Connect("ValueSet(Long_t)", "MyMainFrame", this, "DoSetlabel()");
        // (ch[i]->GetNumberEntry())->Connect("ReturnPressed()", "MyMainFrame", this, "DoSetlabel()");

        this->AddFrame(ch[i], new TGLayoutHints(kLHintsBottom | kLHintsRight | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
    }

    fRead  = new TGTextButton(this, "Read");
    fWrite = new TGTextButton(this, "Write");

    fRead->Connect("Clicked()", "SISModule", this, "ReadFile()");
    fRead->Resize(80,40);
    this->AddFrame(fRead, new TGLayoutHints( kLHintsCenterX | kLHintsCenterY,
                                            3, 2, 2, 2));

    fWrite->Connect("Clicked()", "SISModule", this, "WriteFile()");
    fWrite->Resize(80,40);
    this->AddFrame(fWrite, new TGLayoutHints(kLHintsRight | kLHintsExpandX, 3, 2, 2, 2));

    this->SetLayoutManager(new TGMatrixLayout(this, 17, 2, 5, 0));
}

//-----------------------------------------------------------------------------
//
SISModule::~SISModule()
{
   // Clean up main frame...
   Cleanup();
}

//-----------------------------------------------------------------------------
//
void SISModule::ReadFile(const Char_t *szFileIn) {
  fFileName = szFileIn;
  ReadFile();
}

//-----------------------------------------------------------------------------
//
void SISModule::ReadFile() {
    //
    // needs to be rewriten in ROOT style
    //
    
  FILE *fin;

  Int_t i=0, th=0;
  
  fin=fopen(fFileName, "r");
  if (fin == NULL) perror ("Error opening file");
  printf("Reading file : %s\n", fFileName);
  while( !feof(fin) ) {
    fscanf(fin, "%*s %*s %d", &th);
    // printf("i %i, th %i\n", i, th);
    ch[i]->SetIntNumber( th );
    i++;
    if(i>15) break;
  }
  
  fclose(fin);
}

//-----------------------------------------------------------------------------
//
void SISModule::WriteFile() {
    //
    // needs to be rewriten in ROOT style
    //

  Int_t th=0;
  TString strMode="low";

  FILE *fout;
  fout=fopen("test.dat", "w"); // for debugging
  fout=fopen(fFileName, "w");

  printf("\nWriting in file : %s\n", fFileName);
  
  for(int i=0; i<kMaxCh; i++){
    th = ch[i]->GetIntNumber();
    
      // find out if this is _he_ threshold file
    if ( strstr(fFileName, "_he_") ) {
        //printf(       "set thr_he_val(%i)\t %i\n", i, th);
        fprintf(fout, "set thr_he_val(%i)\t %i\n", i, th);
        strMode = "high";
    }
    else {
        //printf(       "set thr_val(%i)\t %i\n", i, th);
        fprintf(fout, "set thr_val(%i)\t %i\n", i, th);
        strMode = "low"; 
    }
  }
  printf("done!\n");

  fclose(fout);

  // creating the .tcl writing command
  //
  TString strCommand = "/home/lyso/ems_setup/daq/set_thresholds.tcl " +
  fModuleName + " " + 
  strMode +" "+
  "/home/lyso/ems_setup/daq/" + fFileName;

  gSystem->Sleep(100);
  
  //printf("%s\n", strCommand.Data() );
  gSystem->Exec( strCommand );
  
}
