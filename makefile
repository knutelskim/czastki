CC := g++
SRCDIR := src
BUILDDIR := build
BINDIR :=bin
TARGET := main
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -c -Wall
INC := -I include

.PHONY: run clean

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -o $@ $<

$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CC) $^ -o $(BINDIR)/$(TARGET)

clean:
	-rm -f $(BUILDDIR)/*.o

run:
	./$(BINDIR)/$(TARGET)