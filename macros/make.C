{
	gSystem->CompileMacro("SISModule.C", 
			      "kfOc", 
			      "lib/SISModule");

	gSystem->CompileMacro("threshold_setter.C", 
			      "kfOc", 
			      "lib/threshold_setter");
	gSystem->Exit(0);
}
