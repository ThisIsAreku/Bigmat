all: lib test doc

lib:
	$(MAKE) -C bigmat

test:
	$(MAKE) -C test
exectest: lib test
	$(MAKE) -C test exec

doc:
	$(MAKE) -C doc

%:
	$(MAKE) -C bigmat $@
	$(MAKE) -C test $@
	$(MAKE) -C doc $@


.PHONY: lib test doc %
