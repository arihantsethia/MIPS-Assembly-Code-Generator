/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ID = 259,
     AUTO = 260,
     BREAK = 261,
     CASE = 262,
     CHAR = 263,
     CONST = 264,
     CONTINUE = 265,
     DEFAULT = 266,
     DO = 267,
     DOUBLE = 268,
     ELSE = 269,
     ENUM = 270,
     EXTERN = 271,
     FLOAT = 272,
     FOR = 273,
     GOTO = 274,
     IF = 275,
     INT = 276,
     LONG = 277,
     REGISTER = 278,
     RETURN = 279,
     SHORT = 280,
     SIGNED = 281,
     SIZEOF = 282,
     STATIC = 283,
     STRUCT = 284,
     SWITCH = 285,
     TYPEDEF = 286,
     UNION = 287,
     UNSIGNED = 288,
     VOID = 289,
     VOLATILE = 290,
     WHILE = 291,
     PLUS = 292,
     MINUS = 293,
     TIMES = 294,
     DIVIDE = 295,
     MODULO = 296,
     EQUALS = 297,
     BITAND = 298,
     BITOR = 299,
     BITXOR = 300,
     NOT = 301,
     LESS = 302,
     GREATER = 303,
     HASH = 304,
     DOLLAR = 305,
     ATRATE = 306,
     LS = 307,
     RS = 308,
     LB = 309,
     RB = 310,
     LP = 311,
     RP = 312,
     QMARK = 313,
     COLON = 314,
     DOT = 315,
     SEMI = 316,
     COMMA = 317,
     PLUSEQ = 318,
     MINUSEQ = 319,
     TIMESEQ = 320,
     DIVEQ = 321,
     MODULOEQ = 322,
     EMPEQ = 323,
     AND = 324,
     OR = 325,
     REQUALS = 326,
     NOTEQUAL = 327,
     LESSEQ = 328,
     GREATEREQ = 329,
     INCR = 330,
     DECR = 331,
     LSHIFT = 332,
     RSHIFT = 333,
     OREQ = 334,
     XOREQ = 335,
     PTRREF = 336,
     LSHIFTEQ = 337,
     RSHIFTEQ = 338,
     REAL = 339,
     INTPTR = 340,
     LOWER_THAN_ELSE = 341
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define AUTO 260
#define BREAK 261
#define CASE 262
#define CHAR 263
#define CONST 264
#define CONTINUE 265
#define DEFAULT 266
#define DO 267
#define DOUBLE 268
#define ELSE 269
#define ENUM 270
#define EXTERN 271
#define FLOAT 272
#define FOR 273
#define GOTO 274
#define IF 275
#define INT 276
#define LONG 277
#define REGISTER 278
#define RETURN 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define PLUS 292
#define MINUS 293
#define TIMES 294
#define DIVIDE 295
#define MODULO 296
#define EQUALS 297
#define BITAND 298
#define BITOR 299
#define BITXOR 300
#define NOT 301
#define LESS 302
#define GREATER 303
#define HASH 304
#define DOLLAR 305
#define ATRATE 306
#define LS 307
#define RS 308
#define LB 309
#define RB 310
#define LP 311
#define RP 312
#define QMARK 313
#define COLON 314
#define DOT 315
#define SEMI 316
#define COMMA 317
#define PLUSEQ 318
#define MINUSEQ 319
#define TIMESEQ 320
#define DIVEQ 321
#define MODULOEQ 322
#define EMPEQ 323
#define AND 324
#define OR 325
#define REQUALS 326
#define NOTEQUAL 327
#define LESSEQ 328
#define GREATEREQ 329
#define INCR 330
#define DECR 331
#define LSHIFT 332
#define RSHIFT 333
#define OREQ 334
#define XOREQ 335
#define PTRREF 336
#define LSHIFTEQ 337
#define RSHIFTEQ 338
#define REAL 339
#define INTPTR 340
#define LOWER_THAN_ELSE 341




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 5 "grammar.y"

		class AST* node ;
		int number ;
		char* name ;
	


/* Line 2068 of yacc.c  */
#line 230 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


