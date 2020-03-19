EXE ?= test

PWD :=./bin
BUILD_PATH := build
STATIC_EXE ?= static_$(EXE)
TARGET_PATH := lib
 
STATIC_TARGET := $(PWD)/$(STATIC_EXE)

INCL := ./include/
LIB  := ./lib/
LIB_NAME := test
FLAG := -static


all:CHECKDIR ECHO $(STATIC_TARGET)
	@echo "succeed"

static_app: 
	$(CXX)  main.cpp -I$(INCL) -L$(LIB) -l$(LIB_NAME) -o $(STATIC_EXE)

CHECKDIR:
	mkdir -p $(PWD) $(LIB) $(BUILD_PATH)

ECHO:
	make -C source
	@echo "begin compile...."

$(STATIC_TARGET): 
	$(CXX) main.cpp -o $(STATIC_TARGET) -I$(INCL) -L$(LIB) -l$(LIB_NAME) 
		 
clean:
	rm -rf bin/$(STATIC_EXE) $(BUILD_PATH)/*.o $(TARGET_PATH)/*.{a,so}
