include common.mk

.PHONY: all static shared samples clean

all:
	cd src && $(MAKE) $@

static:
	cd src && $(MAKE) $@

shared:
	cd src && $(MAKE) $@

samples: static
	cd samples && $(MAKE) all

install: all
	mkdir -p $(INSTALL_INC) $(INSTALL_LIB)
	install -p -m 0644 src/*.h $(INSTALL_INC)
	install -p -m 0644 src/$(QUOTE_STATIC_LIB_NAME) src/$(QUOTE_SHARED_LIB_NAME) $(INSTALL_LIB)

uninstall:
	rm -fR $(INSTALL_INC)
	rm -f $(INSTALL_LIB)/$(QUOTE_STATIC_LIB_NAME) $(INSTALL_LIB)/$(QUOTE_SHARED_LIB_NAME)

clean:
	cd src && $(MAKE) $@
	cd samples && $(MAKE) $@
