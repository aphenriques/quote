INSTALL_TOP:=/usr/local
INSTALL_INC:=$(INSTALL_TOP)/include/quote
INSTALL_LIB:=$(INSTALL_TOP)/lib

ifeq ($(shell uname -s),Darwin)
SHARED_LIB_EXTENSION:=dylib
else
SHARED_LIB_EXTENSION:=so
endif

PROJECT_STATIC_LIB_NAME:=libquote.a
PROJECT_SHARED_LIB_NAME:=libquote.$(SHARED_LIB_EXTENSION)

CXXFLAGS:=-std=c++11 -O3 -I/usr/local/include
LDFLAGS:=-L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/ -L/usr/lib
PROJECT_LDLIBS:=-lcurl
