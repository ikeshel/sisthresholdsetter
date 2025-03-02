#pragma once

/******************************************************************************
 *   SIS module threshold modifier                                            *
 *                                                                            *
 *   29.01.2020 Juelich                                                       *
 *                                                                            *
 *   i.keshelashvili@fz-juelich.de                                            *
 *                                                                            *
 *****************************************************************************/

#include <cstdlib>
#include <cstdio>

#include <TROOT.h>
#include <TClass.h>
#include <TApplication.h>
#include <TVirtualX.h>
#include <TVirtualPadEditor.h>

#include <TGResourcePool.h>
#include <TGListBox.h>
#include <TGListTree.h>
#include <TGFSContainer.h>
#include <TGClient.h>
#include <TGFrame.h>
#include <TGIcon.h>
#include <TGLabel.h>
#include <TGButton.h>
#include <TGTextEntry.h>
#include <TGNumberEntry.h>
#include <TGMsgBox.h>
#include <TGMenu.h>
#include <TGCanvas.h>
#include <TGComboBox.h>
#include <TGTab.h>
#include <TGSlider.h>
#include <TGDoubleSlider.h>
#include <TGFileDialog.h>
#include <TGTextEdit.h>
#include <TGShutter.h>
#include <TGProgressBar.h>
#include <TGColorSelect.h>
#include <TGDockableFrame.h>
#include <TGFontDialog.h>
#include <TGStatusBar.h>

#include <RQ_OBJECT.h>
#include <TRootEmbeddedCanvas.h>
#include <TCanvas.h>
#include <TColor.h>
#include <TH1.h>
#include <TH2.h>
#include <TRandom.h>
#include <TSystem.h>
#include <TSystemDirectory.h>
#include <TEnv.h>
#include <TFile.h>
#include <TKey.h>

#include "Riostream.h"

//RQ_OBJECT("SISModule")

const Int_t kMaxCh = 16; // ADC channels per module

///////////////////////////////////////////////////////////////////////////////
//
class SISModule : public TGGroupFrame {
    

private:
    TString fModuleName;
   
protected:
   TGLabel        *fChLbl[kMaxCh];
   TGNumberEntry  *ch[kMaxCh];
   TGTextButton   *fRead, *fWrite;	

public:
   const  Char_t *fFileName;
   
   SISModule(const TGWindow *, const char *, UInt_t , GContext_t , FontStruct_t , Pixel_t );
   virtual ~SISModule();

   void ReadFile();
   void ReadFile(const Char_t *);
   void WriteFile();
  
   ClassDef(SISModule, 2)
};
