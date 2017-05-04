include common.mk

INSTALL_TOP:=/usr/local
INSTALL_INC:=$(INSTALL_TOP)/include/$(PROJECT)
INSTALL_LIB:=$(INSTALL_TOP)/lib

.PHONY: all static shared samples install uninstall clean

all:
	cd $(PROJECT_LIB_DIR) && $(MAKE) $@

static:
	cd $(PROJECT_LIB_DIR) && $(MAKE) $@

shared:
	cd $(PROJECT_LIB_DIR) && $(MAKE) $@

samples: static
	cd $(PROJECT_BIN_DIR) && $(MAKE) all

install: all
	mkdir -p $(INSTALL_INC) $(INSTALL_INC)/exception $(INSTALL_LIB)
	install -p -m 0644 $(PROJECT_LIB_DIR)/*.hpp $(INSTALL_INC)
	install -p -m 0644 $(PROJECT_LIB_DIR)/exception/*.hpp $(INSTALL_INC)/exception
	install -p -m 0644 $(PROJECT_LIB_DIR)/$(PROJECT_STATIC_LIB) $(PROJECT_LIB_DIR)/$(PROJECT_SHARED_LIB) $(INSTALL_LIB)

uninstall:
	$(RM) -R $(INSTALL_INC)
	$(RM) $(INSTALL_LIB)/$(PROJECT_STATIC_LIB) $(INSTALL_LIB)/$(PROJECT_SHARED_LIB)

clean:
	cd $(PROJECT_LIB_DIR) && $(MAKE) $@
	cd $(PROJECT_BIN_DIR) && $(MAKE) $@