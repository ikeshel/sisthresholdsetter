//////////////////////////////////////////////////////////////////////////
//                                                                      //
// LinkDef.h     Irakli K.      31.01.2020                              //
//                                                                      //
// JePoLib dictionary header file.                                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifdef __CINT__

// turn everything off
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all typedef;

#pragma link C++ nestedclasses;
#pragma link C++ nestedtypedef;

// enums
//#pragma link C++ enum E...;

// typedefs
//#pragma link C++ typedef ..._t;

//#pragma link C++ namespace T;

// common classes
#pragma link C++ class SISModule+;
#pragma link C++ class SISMainWindow+;

#endif
