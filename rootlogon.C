
#include "include/SISMainWindow.h"
#include "include/SISModule.h"

{
    //
    gSystem->SetIncludePath("/home/lyso/irakli/sisthresholdsetter/include");
    
    //
    TString strLibs[] = {"libJePo.so"};    
    int nn = sizeof(strLibs)/sizeof(TString);
    
    //
    for(int i=0; i<nn;i++)
    {
        if(gSystem->Load(strLibs[i]))
            cerr << "Error loading lybrary : " << strLibs[i] << endl;
        else
            cout << "Loaded lib: " << strLibs[i] << endl;
    }
    
   //new SISMainWindow(gClient->GetRoot(), 1000, 800);
//    SISMainWindow thr(gClient->GetRoot(), 1000, 800);
}
