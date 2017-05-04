PROJECT:=quote

PROJECT_LIB_DIR:=src
PROJECT_BIN_DIR:=samples
PROJECT_STATIC_LIB:=lib$(PROJECT).a

# some variables require PROJECT_ROOT_DIR definition. That's why = is used instead of := for their definition
PROJECT_INCLUDE_DIRS=$(PROJECT_ROOT_DIR)/$(PROJECT_LIB_DIR)
PROJECT_LDLIBS=$(PROJECT_ROOT_DIR)/$(PROJECT_LIB_DIR)/$(PROJECT_STATIC_LIB) -lcurl
PROJECT_SYSTEM_INCLUDE_DIRS:=/usr/local/include
PROJECT_LIB_DIRS:=/usr/local/lib
# TODO with c++17: remove -Wno-unused-parameter and -Wno-unused-but-set-parameter and use [[maybe_unused]] attribute
PROJECT_CXXFLAGS:=-std=c++14 -O0 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wno-missing-braces -Wno-unused-parameter -pedantic

ifeq ($(shell uname -s),Darwin)
# -Wweak-vtables is a clang feature
PROJECT_CXXFLAGS+=-Wweak-vtables
SHARED_LIB_EXTENSION:=dylib
PROJECT_LDFLAGS:=-undefined dynamic_lookup
else
PROJECT_CXXFLAGS+=-Wno-unused-but-set-parameter
SHARED_LIB_EXTENSION:=so
PROJECT_LDFLAGS:=
endif

PROJECT_SHARED_LIB:=lib$(PROJECT).$(SHARED_LIB_EXTENSION)