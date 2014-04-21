LEX_FILE = lex.l
YACC_FILE = grammar.y
YACC_SOURCES = ast.cpp symbolTable.cpp
GENERATED_SOURCES = lex.yy.c y.tab.c
GENERATED_HEADERS = y.tab.h
YACC_OBJECTS = $(YACC_SOURCES:.cpp=.o) lex.yy.o y.tab.o

CC = g++ 
LL = flex
YC = yacc

.PHONY: all

all: $(LEX) $(YACC)

$(LEX): $(LEX_FILE)
	$(LL) $(LEX_FILE)

$(YACC): $(YACC_FILE)
	$(YC) -d $(YACC_FILE)
	$(CC) -c -w $(YACC_SOURCES) $(GENERATED_SOURCES)

clean:
	@- $(RM) $(YACC_OBJECTS) $(GENERATED_SOURCES) $(GENERATED_HEADERS)