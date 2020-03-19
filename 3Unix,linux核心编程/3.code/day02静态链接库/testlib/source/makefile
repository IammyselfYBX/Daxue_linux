LIB_NAME ?= test

PWD := ..
BUILD_PATH := ../build
STATIC_NAME ?= lib$(LIB_NAME).a

TARGET_PATH := ../lib
STATIC_TARGET := $(TARGET_PATH)/$(STATIC_NAME)

SOURCE :=$(wildcard *.cpp)
OBJS := $(patsubst %.cpp, $(BUILD_PATH)/%.o, $(wildcard *.cpp)) 

all:$(STATIC_TARGET) 

#生成静态库 libtest.a
$(STATIC_TARGET):$(OBJS) 
	ar -crv $(STATIC_TARGET) $(OBJS) 
	ranlib $(STATIC_TARGET)

#生成二进制文件(*.o)
$(OBJS): $(wildcard *.cpp)  
	$(CXX) -c $< -o $@

clean:
	rm -rf $(BUILD_PATH)/*.o $(TARGET_PATH)/*.{a,so}

.PHONY: all clean
#
#
#
#
#编译正确的版本
#LIB_NAME?= test
#STATIC_NAME ?= lib$(LIB_NAME).a
#SHARE_NAME  ?= lib$(LIB_NAME).so

#SOURCE :=$(wildcard *.cpp)
#OBJS := $(patsubst %.cpp,%.o,$(SOURCE))
 
#all:$(STATIC_NAME) $(SHARE_NAME)
	 
#$(STATIC_NAME):$(OBJS)
#	rm -rf $(STATIC_NAME)
#	ar cru $(STATIC_NAME) $(OBJS)
#	ranlib $(STATIC_NAME)	 

#$(SHARE_NAME):$(OBJS)
#	g++ -shared -fPIC $(SOURCE) -o $(SHARE_NAME)

#$(OBJS): $(wildcard *.cpp)  
#	$(CXX) -c $< -o $@

#install:
#	mv $(STATIC_NAME) ../lib
#	mv $(SHARE_NAME) ../lib
	
#clean:
#	rm -rf $(OBJS) $(STATIC_NAME) $(SHARE_NAME)
#	
