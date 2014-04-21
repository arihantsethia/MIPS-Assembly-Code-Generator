%option yylineno

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
	#include <stdio.h>
	#include "y.tab.h"
	#include "headers/ast.h"
%}

%%
[ \t\n\b]	;
"auto" 		return AUTO;
"char" 		return CHAR;
"else" 		return ELSE;
"float" 	return FLOAT;
"if" 		return IF;
"int" 		return INT;
"long" 		return LONG;
"while" 	return WHILE;
"bool"		return BOOL;
"true"		{
				yylval.vBool = true;
				return BOOLEAN;
			}
"false"		{
				yylval.vBool = false;
				return BOOLEAN;
			}
"+" 		return PLUS;
"-" 		return MINUS;
"*" 		return TIMES;
"/" 		return DIVIDE;
"=" 		return EQUALS;
"<" 		return LESS;
">" 		return GREATER;
"[" 		return LS;
"]" 		return RS;
"{" 		return LB;
"}" 		return RB;
"(" 		return LP;
")" 		return RP;
":" 		return COLON;
"." 		return DOT;
";" 		return SEMI;
"," 		return COMMA;
"&&" 		return AND;
"||" 		return OR;
"==" 		return REQUALS;
"!=" 		return NOTEQUAL;
"<=" 		return LESSEQ;

{L}({L}|{D})*	{
					yylval.vId = strdup(yytext);
					return ID;
				} 
{D}({D})*		{	
					yylval.vInt = atoi(strdup(yytext));
					return NUMBER;
				}
{D}*"."{D}+({E})?{FS}?	{
					yylval.vFloat = atof(strdup(yytext));
					return DECIMAL ;
				}
.				{ /* ignore bad characters */ }
%%

int yywrap(void)
{
	return 1;
}
