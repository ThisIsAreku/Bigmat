# Makefile
# Copyright 2013 Alexandre Boucey <alexandre.boucey@alumni.univ-avignon.fr>
FLAGS		 = 
CXXFLAGS	 = -std=c++11 -fPIC -W -Wall -Wextra -Wno-unused-parameter -I../bigmat/headers/
LDFLAGS		 = -L../bigmat/lib/ -lbigmat
DEBUGFLAGS	 = -O0 -D _DEBUG -g
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

SOURCES_DIR	 = src
HEADERS_DIR	 = headers

NAME    = bigmat_tests
MAJOR	= 0
MINOR	= 1

VERSION = $(MAJOR).$(MINOR)
TARGET	= $(NAME)-$(VERSION)
SOURCES = $(shell find $(SOURCES_DIR)/ -name "*.cpp")
HEADERS = $(shell find $(HEADERS_DIR)/ -name "*.hpp")
OBJECTS = $(SOURCES:$(SOURCES_DIR)/%.cpp=obj/%.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

all: init compile

debug: CXXFLAGS+= $(DEBUGFLAGS)
debug: init compile

build: $(OBJECTS)
compile: $(TARGET)

exec: all
	./exec.sh ./bin/$(TARGET)

format:
	astyle $(HEADERS) $(SOURCES)

$(TARGET): $(OBJECTS)
	$(CXX) $(FLAGS) $(LDFLAGS) -o bin/$@ $^

obj/%.o: src/%.cpp
	-@if [ ! -d "$(shell dirname $@)" ]; then mkdir -p $(shell dirname $@); fi 
	$(CXX) $(CXXFLAGS) -c -I$(HEADERS_DIR) -o $@ $<

init:
	@echo "Using $(CXX)"
	$(CXX) --version
	mkdir -p obj bin

.PHONY: clean mrproper

clean:
	rm -rf obj

mrproper: clean
	rm -rf bin
