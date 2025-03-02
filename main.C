
/******************************************************************************
 *   SIS module threshold modifier                                            *
 *                                                                            *
 *   29.01.2020 Juelich                                                       *
 *                                                                            *
 *   i.keshelashvili@fz-juelich.de                                            *
 *                                                                            *
 *****************************************************************************/

#include "TROOT.h"
#include "TRint.h"
#include <TROOT.h>
#include <TApplication.h>

#include "SISModule.h"
#include "SISMainWindow.h"

//-----------------------------------------------------------------------------
void PrintIntro() {
    
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{   
   TApplication *theApp= new TApplication("App", &argc, argv);
   
   new SISMainWindow(gClient->GetRoot(), 200, 200);

   theApp->Run();

   return 0;
}
