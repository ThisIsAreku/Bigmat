all: lib test

lib:
	$(MAKE) -C bigmat

test:
	$(MAKE) -C test
