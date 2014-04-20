program_NAME_flex := lex.l
program_NAME_yacc := grammar.y
FLEX := 

program_CXX_SRCS := $(wildcard *.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS := $(program_C_OBJS) $(program_CXX_OBJS)
program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
program_LIBRARIES :=

CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))

.PHONY: all clean distclean

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
