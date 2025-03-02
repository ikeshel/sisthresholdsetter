//______________________________________________________________________________
void htmldoc()
{
    gROOT->Reset();
    if (!gROOT->GetClass("JePoLib")) 
        gSystem->Load("libJePo.so");

    THtml h;
    h.SetInputDir(".:src:include");
    h.SetOutputDir("htmldoc");
    h.SetAuthorTag("* Author:");
    h.SetProductName("JePoLib");

    h.MakeAll();
}