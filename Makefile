########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

# Makefile settings - Can be customized.
APPNAME = rummy
EXT = .cpp
OBJEXT = .obj
SRCDIR = ./
OBJDIR = obj
LIBDIR = lib
LIBOBJDIR = lib/obj
EXECDIR = executable
INCLUDEDIR = lib/include

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
LIBOBJ = $(wildcard $(LIBOBJDIR)/*$(OBJEXT))
# UNIX-based OS variables & settings
RM = rm -f
DELOBJ = $(OBJ)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: buildlib $(APPNAME)

buildlib:
	cd $(LIBDIR) && make

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $(EXECDIR)/$@ $^ $(LIBOBJ) $(LDFLAGS)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $< -I $(INCLUDEDIR)

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
.PHONY: clean

clean:
	cd $(LIBDIR) && make clean
	$(RM) $(DELOBJ) $(EXECDIR)/$(APPNAME)