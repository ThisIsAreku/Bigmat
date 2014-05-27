all: lib test doc

lib:
	$(MAKE) -C bigmat

test:
	$(MAKE) -C test

doc:
	$(MAKE) -C doc

%:
	$(MAKE) -C bigmat $@
	$(MAKE) -C test $@
	$(MAKE) -C doc $@

.PHONY: lib test doc clean mrproper
