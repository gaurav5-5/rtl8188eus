# SPDX-License-Identifier: GPL-2.0-only
# Standalone wrapper; Kbuild in this directory lists the objects.
KVER ?= $(shell uname -r)
KDIR ?= /lib/modules/$(KVER)/build

all: modules

modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) clean

.PHONY: all modules clean
