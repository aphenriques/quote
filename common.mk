INSTALL_TOP:=/usr/local
INSTALL_INC:=$(INSTALL_TOP)/include/quote
INSTALL_LIB:=$(INSTALL_TOP)/lib

# TODO with c++17: remove -Wno-unused-parameter and -Wno-unused-but-set-parameter and use [[maybe_unused]] attribute
CXXFLAGS:=-std=c++11 -O3 -I/usr/local/include -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wno-missing-braces -Wno-unused-parameter -pedantic
LDFLAGS:=-L/usr/local/lib -L/usr/lib/x86_64-linux-gnu/ -L/usr/lib

PROJECT_LDLIBS:=-lcurl

ifeq ($(shell uname -s),Darwin)
# -Wweak-vtables is a clang feature
CXXFLAGS+=-Wweak-vtables
SHARED_LIB_EXTENSION:=dylib
else
CXXFLAGS+=-Wno-unused-but-set-parameter
SHARED_LIB_EXTENSION:=so
endif

PROJECT_STATIC_LIB_NAME:=libquote.a
PROJECT_SHARED_LIB_NAME:=libquote.$(SHARED_LIB_EXTENSION)
