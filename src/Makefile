include ../common.mk

SRC_DIRS:=.

CXXFLAGS+=-fPIC
ARFLAGS:=rcs

SRCS:=$(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))
OBJS:=$(addsuffix .o, $(basename $(SRCS)))
DEPS:=$(addsuffix .d, $(basename $(SRCS)))

.PHONY: all static shared clean

all: static shared

static: $(QUOTE_STATIC_LIB_NAME)

shared: $(QUOTE_SHARED_LIB_NAME)

$(QUOTE_STATIC_LIB_NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(QUOTE_SHARED_LIB_NAME): $(OBJS)
	$(CXX) -shared $(LDFLAGS) $(LDLIBS) $^ -o $@

%.d: %.cpp
	$(CXX) $(CXXFLAGS) -MP -MM -MF $@ -MT '$@ $(addsuffix .o, $(basename $<))' $<

clean:
	$(RM) $(DEPS) $(OBJS) $(QUOTE_STATIC_LIB_NAME) $(QUOTE_SHARED_LIB_NAME)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
