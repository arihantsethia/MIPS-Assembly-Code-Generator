BUILD_SUBDIRS = yacc
GRAMMAR_SOURCES = src/ast.cpp src/symbolTable.cpp
YACC_OBJECTS = $(GRAMMAR_SOURCES:.cpp=.o) src/lex.yy.o src/y.tab.o
YACC_EXECUTABLE = yaccparser

program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
program_LIBRARIES :=

CC = g++
CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))


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