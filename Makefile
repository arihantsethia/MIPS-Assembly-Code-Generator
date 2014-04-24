BUILD_SUBDIRS = yacc
GRAMMAR_SOURCES = src/ast.cpp src/symbolTable.cpp
YACC_SOURCES = src/lex.l src/grammar.y
YACC_OBJECTS = $(GRAMMAR_SOURCES:.cpp=.o) src/lex.yy.o src/y.tab.o
CODE_OBJECTS = src/codegen/lex.yy.o src/codegen/y.tab.o
CODE_SOURCES = src/codegen/lex.l src/codegen/codegen.y
YACC_EXECUTABLE = yaccparser
CODE_EXECUTABLE = codegenrator

program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
program_LIBRARIES :=

CC = g++
CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))


.PHONY: all clean distclean grammar_exeuytable parser_executable yacc_executable

all: executable 

executable: $(YACC_EXECUTABLE) $(CODE_EXECUTABLE)

$(YACC_EXECUTABLE): $(GRAMMAR_SOURCES) $(YACC_SOURCES)
	$(MAKE) -C src
	$(CC) $(YACC_OBJECTS) -o $(YACC_EXECUTABLE)

$(CODE_EXECUTABLE): $(CODE_SOURCES)
	$(MAKE) -C src/codegen
	$(CC) $(CODE_OBJECTS) -o $(CODE_EXECUTABLE)

clean:
	@- $(RM) $(YACC_EXECUTABLE) $(CODE_EXECUTABLE)
	@- $(RM) $(PARSER_OBJECTS)	$(CODE_OBJECTS)
	$(MAKE) -C src $@
	$(MAKE) -C src/codegen $@
distclean: clean