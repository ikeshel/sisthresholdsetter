#
# Irakli K.    31.01.2020
#

#ROOTFLAGS = $(shell root-config --cflags --glibs)
ROOTFLAGS = $(shell root-config --cflags --ldflags --libs --glibs)

all:
	@echo "Creating Dict.cxx"
	@rootcint -f Dict.cxx -I$(PWD)/include/ SISModule.h SISMainWindow.h LinkDef.h
	@echo "Done."
	
	@echo "Creating shared library"
	@g++ --shared -o libJePo.so src/SISModule.C src/SISMainWindow.C Dict.cxx -I$(PWD)/include/ \
	$(ROOTFLAGS) \
	-fPIC -Wall 
	@echo "Done."
	
	@echo "Creating executable"
	@g++ -o sisthresholdsetter main.C $(PWD)/libJePo.so -I$(PWD)/include/ $(ROOTFLAGS) 
	@echo "Done."

docs:
	@echo "Creating HTML documentation"
	@rm -r -f htmldoc
	@root -b -n -q macros/htmldoc.C
	@echo "Done."

clean:
	rm -v Dict* libJePo.so sisthresholdsetter
