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

#include "SISModule.h"

const TString strFileList[]={
    "thresholds/thr_modA",
    "thresholds/thr_modB",
    "thresholds/thr_modC",
    "thresholds/thr_modD",
    "thresholds/thr_modE",
    "thresholds/thr_modF" };
			     
const TString strFileList_he[]={
    "thresholds_he/thr_he_modA",  
    "thresholds_he/thr_he_modB",  
    "thresholds_he/thr_he_modC",  
    "thresholds_he/thr_he_modD",  
    "thresholds_he/thr_he_modE",  
    "thresholds_he/thr_he_modF" };
			     

const TString strModuleName[]={"lyso_a", "lyso_b", "lyso_c", "lyso_d", "lyso_e", "lyso_f"};

class SISMainWindow : public TGMainFrame {

//RQ_OBJECT("SISMainWindow")
    
private:
    
    TGTab       *fTab;
    TGStatusBar *fStatusBar;

public:
    SISMainWindow(const TGWindow *p, UInt_t w, UInt_t h);
    virtual ~SISMainWindow();

    Int_t NModule;// = sizeof(strModuleName)/sizeof(TString); 
    Int_t NChannel;// = kMaxCh * NModule;
    
   // slots
   void CloseWindow();
   
   // void DoExit();
   // void DoDraw();
   // void SetStatusText(const char *txt, Int_t pi);
   // void EventInfo(Int_t event, Int_t px, Int_t py, TObject *selected);

   ClassDef(SISMainWindow, 2)
};


