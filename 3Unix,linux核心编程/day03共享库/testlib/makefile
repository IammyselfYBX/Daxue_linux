EXE ?= test

PWD :=bin
SHARE_EXE  ?= share_$(EXE)
BUILD_PATH := build
TARGET_PATH := lib
SHARE_TARGET := $(PWD)/$(SHARE_EXE)

INCL := -I./include/
LIB  := -L./lib/
LIB_NAME := test
FLAG := -share
 
all:CHECKDIR ECHO $(SHARE_TARGET)
	@echo "SUCCEED"

CHECKDIR:
	mkdir -p $(PWD) $(TARGET_PATH) $(BUILD_PATH)

ECHO:
	make -C source
	@echo "begin compile...."

$(SHARE_TARGET):
	$(CXX)  main.cpp $(INCL) $(LIB) -l$(LIB_NAME) -o $(SHARE_TARGET)
		 
shared_app:
	$(CXX)  main.cpp $(INCL) $(LIB) -l$(LIB_NAME) -o $(SHARE_EXE)
		 
clean:
	rm -rf  $(PWD) $(TARGET_PATH) $(BUILD_PATH)
