all: lib test gui

lib:
	$(MAKE) -C bigmat

gui:
	$(MAKE) -C gui

test:
	$(MAKE) -C test

clean:
	$(MAKE) -C bigmat $@
	$(MAKE) -C test $@
	$(MAKE) -C gui $@


mrproper:
	$(MAKE) -C bigmat $@
	$(MAKE) -C test $@
	$(MAKE) -C gui $@

.PHONY: lib test gui clean mrproper
