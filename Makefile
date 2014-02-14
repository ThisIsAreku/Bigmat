all: lib test

lib:
	$(MAKE) -c bigmat

test:
	$(MAKE) -c test
