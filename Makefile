all: lib test

lib:
	$(MAKE) -C bigmat

test:
	$(MAKE) -C test

clean:
	$(MAKE) -C bigmat $@
	$(MAKE) -C test $@


mrproper:
	$(MAKE) -C bigmat $@
	$(MAKE) -C test $@

