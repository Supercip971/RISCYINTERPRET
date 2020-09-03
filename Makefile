

GCC := g++
LD := ld
PROJDIRS := .
SRCFILES := $(shell find $(PROJDIRS) -type f -name \*.cpp)

OBJFILES := $(patsubst %.cpp,%.o,$(SRCFILES))
HDRFILES := $(shell find $(PROJDIRS) -type f -name \*.h)
%.o: %.cpp $(SRCFILES) $(HDRFILES)
	$(GCC) -c -pthread -std=c++17 -m64 -Wall -g -march=x86-64 -I . -O2 -msse -o $@ $<
 

all: $(OBJFILES)

	@echo "building" 
	$(GCC) $(OBJFILES) -pthread -o build/RISCYINTERPRETER 
	@make run
run:
	./build/RISCYINTERPRETER riscHELLO.rexe -con
debug: 
	./build/RISCYINTERPRETER riscHELLO.rexe -con
make_elf:
	
format:
	clang-format -i --verbose --style=file $(SRCFILES) $(HDRFILES)
clear:
	rm $(OBJFILES)
