include ../common.mk

SRC_DIRS:=.

SRCS:=$(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))
OBJS:=$(addsuffix .o, $(basename $(SRCS)))
DEPS:=$(addsuffix .d, $(basename $(SRCS)))

.PHONY: all static shared clean

all: static shared

static: $(QUOTE_STATIC_LIB_NAME)

shared: $(QUOTE_SHARED_LIB_NAME)

$(QUOTE_STATIC_LIB_NAME): $(OBJS)
	ar rcs $@ $^

$(QUOTE_SHARED_LIB_NAME): $(OBJS)
	$(CXX) -shared $(LDFLAGS) $(LDLIBS) $^ -o $@

%.d: %.cpp
	$(CXX) $(CPPFLAGS) -MP -MM -MF $@ -MT '$@ $(addsuffix .o, $(basename $<))' $<

clean:
	rm -f $(DEPS) $(OBJS) $(QUOTE_STATIC_LIB_NAME) $(QUOTE_SHARED_LIB_NAME)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
