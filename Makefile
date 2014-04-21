<<<<<<< HEAD
BUILD_SUBDIRS = yacc
GRAMMAR_SOURCES = src/ast.cpp src/symbolTable.cpp
YACC_OBJECTS = $(GRAMMAR_SOURCES:.cpp=.o) src/lex.yy.o src/y.tab.o
YACC_EXECUTABLE = yaccparser

=======
program_NAME_flex := lex.l
program_NAME_yacc := grammar.y
FLEX := 

program_CXX_SRCS := $(wildcard *.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_C_OBJS) $(program_CXX_OBJS)
>>>>>>> 4584bb0a9ccfb9a1a5945382028f61df3b4a8ce0
program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
program_LIBRARIES :=

CC = g++
CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))


<<<<<<< HEAD
.PHONY: all clean distclean grammar_exeuytable parser_executable yacc_executable

all: executable

executable: $(YACC_EXECUTABLE)

$(YACC_EXECUTABLE): $(wildcard src/*)
	$(MAKE) -C src
	$(CC) $(YACC_OBJECTS) -o $(YACC_EXECUTABLE)

clean:
	@- $(RM) $(YACC_EXECUTABLE)
	@- $(RM) $(PARSER_OBJECTS)
	$(MAKE) -C src $@
distclean: clean
=======
all: program_NAME

program_NAME: FLEX_COMPILE YACC_COMPILE y.tab.c lex.yy.c
	g++ -w y.tab.c lex.yy.c ast.cpp

FLEX_COMPILE: $(program_NAME_flex)
	flex $(program_NAME_flex)

YACC_COMPILE: FLEX_COMPILE $(program_NAME_yacc)
	yacc -d $(program_NAME_yacc)

clean:
	@- $(RM) lex.yy.c y.tab.c y.tab.h a.out

distclean: clean
>>>>>>> 4584bb0a9ccfb9a1a5945382028f61df3b4a8ce0
