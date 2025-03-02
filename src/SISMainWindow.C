
/******************************************************************************
 *   SIS module threshold modifier                                            *
 *                                                                            *
 *   29.01.2020 Juelich                                                       *
 *                                                                            *
 *   i.keshelashvili@fz-juelich.de                                            *
 *                                                                            *
 *****************************************************************************/

#include "SISModule.h"
#include "SISMainWindow.h"

ClassImp(SISMainWindow)

SISMainWindow::SISMainWindow(const TGWindow *p, UInt_t w, UInt_t h) :
   TGMainFrame(p, w, h)
{
    NModule = sizeof(strModuleName)/sizeof(TString); 
    NChannel = kMaxCh * NModule;
 
    // use hierarchical cleaning
//     this->SetCleanup(kDeepCleanup);

    this->Connect("CloseWindow()", "SISMainWindow", this, "CloseWindow()");
   
    this->SetWindowName("Threshold setter");
    this->SetLayoutBroken(kFALSE); // to follow the window size

    ULong_t ucolor;        // will reflect user color changes
    gClient->GetColorByName("#FFFFFF",ucolor);

    ULong_t ucolor1;        // will reflect user color changes
    gClient->GetColorByName("#888888",ucolor1);

    ULong_t ucolor2;        // will reflect user color changes
    gClient->GetColorByName("#DDDDDD",ucolor2);


    // =========================================
    //
    fTab = new TGTab(this, 300, 300);
    
    TGCompositeFrame *tf_le = fTab->AddTab("Low Energy Threshold");
    TGCompositeFrame *tf_he = fTab->AddTab("High Energy Threshold");
    
    // horizontal frame
    TGHorizontalFrame *HFrame_le = new TGHorizontalFrame(tf_le, 1, 1,
                                                       kHorizontalFrame | kRaisedFrame,ucolor);

    TGHorizontalFrame *HFrame_he = new TGHorizontalFrame(tf_he, 1, 1,
                                                       kHorizontalFrame | kRaisedFrame,ucolor);

    SISModule * Group_le[NModule]; // 

    SISModule * Group_he[NModule]; // 
    
    // over modules
    for(int mod=0; mod<NModule; mod++) {

        if (mod%2) // alternating colors
            ucolor = ucolor1;
        else
            ucolor = ucolor2;      
        
        //
        Group_le[mod] = new SISModule( HFrame_le, 
                                        strModuleName[mod], 
                                        kVerticalFrame | kSunkenFrame,
                                        TGGroupFrame::GetDefaultGC()(), TGGroupFrame::GetDefaultFontStruct(), ucolor);
        Group_le[mod]->ReadFile(strFileList[mod]);
        HFrame_le->AddFrame(Group_le[mod], new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,2,2,2,2));
        
        //
        Group_he[mod] = new SISModule( HFrame_he, 
                                        strModuleName[mod], 
                                        kVerticalFrame | kSunkenFrame,
                                        TGGroupFrame::GetDefaultGC()(), TGGroupFrame::GetDefaultFontStruct(), ucolor);
        Group_he[mod]->ReadFile(strFileList_he[mod]);
        HFrame_he->AddFrame(Group_he[mod], new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,2,2,2,2));                
    }

    tf_le->AddFrame(HFrame_le, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,2,2,2,2));
    tf_he->AddFrame(HFrame_he, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,2,2,2,2));
     
    this->AddFrame(fTab, new TGLayoutHints(kLHintsTop | kLHintsExpandX | kLHintsExpandY, 2, 2, 5, 1));
 
    //-----------------------------------------------------------------------------------
    // status bar
    TGStatusBar *fStatusBar = new TGStatusBar(this,1, 30);
    fStatusBar->SetName("fStatusBar");
    this->AddFrame(fStatusBar, new TGLayoutHints(kLHintsBottom | kLHintsExpandX,0,0,2,0));

    // Main window stuff
    this->SetMWMHints(kMWMDecorAll, kMWMFuncAll, kMWMInputModeless);
    this->MapSubwindows();

    this->SetWMSizeHints (600, 600, 3000, 3000, 5, 5);
    this->Resize(this->GetDefaultSize());
    this->MapWindow();
    this->Resize(1200,600);
}


SISMainWindow::~SISMainWindow()
{
   // Clean up main frame...
   Cleanup();
}

void SISMainWindow::CloseWindow() {
    // Got close message for this MainFrame. Terminates the application.
    std::cout << "End of the program" << std::endl;
    gApplication->Terminate();
}
