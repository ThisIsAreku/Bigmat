# Makefile
# Copyright 2013 Alexandre Boucey <alexandre.boucey@alumni.univ-avignon.fr>
FLAGS		 = -shared -fpic -std=c++0x
CXXFLAGS	 = -fpic -W -Wall -Wextra 
LDFLAGS		 = -shared
DEBUGFLAGS	 = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

SOURCES_DIR	 = src
HEADERS_DIR	 = headers

NAME    = bigmat
MAJOR	= 0
MINOR	= 1

VERSION = $(MAJOR).$(MINOR)
TARGET	= lib$(NAME).so.$(VERSION)
SOURCES = $(shell find $(SOURCES_DIR)/ -name "*.cpp")
HEADERS = $(shell find $(HEADERS_DIR)/ -name "*.h")
OBJECTS = $(SOURCES:$(SOURCES_DIR)/%.cpp=obj/%.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

all: init compile

debug: CXXFLAGS+= -g
debug: init compile

build: $(OBJECTS)
compile: $(TARGET)

format:
	astyle $(HEADERS) $(SOURCES)

$(TARGET): $(OBJECTS)
	$(CXX) $(FLAGS) $(LDFLAGS) -o lib/$@ $^
	ln -fs $@ lib/lib$(NAME).so

obj/%.o: $(SOURCES_DIR)/%.cpp
	-@if [ ! -d "$(shell dirname $@)" ]; then mkdir -p $(shell dirname $@); fi 
	$(CXX) $(FLAGS) $(CXXFLAGS) -c -I$(HEADERS_DIR) -o $@ $<

init:
	@echo "Using $(CXX)"
	$(CXX) --version
	mkdir -p obj lib

.PHONY: clean mrproper

clean:
	rm -rf obj

mrproper: clean
	rm -rf lib
