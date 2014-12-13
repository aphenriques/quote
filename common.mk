INSTALL_TOP= /usr/local
INSTALL_INC= $(INSTALL_TOP)/include/quote
INSTALL_LIB= $(INSTALL_TOP)/lib

PROJECT_STATIC_LIB_NAME:=libquote.a
PROJECT_SHARED_LIB_NAME:=libquote.so

CXXFLAGS:=-std=c++11 -O3 -I/usr/local/include
LDFLAGS:=-L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/ -L/usr/lib
PROJECT_LDLIBS:=-lcurl
