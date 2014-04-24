%{
#include "../headers/headers.h"
using namespace std;
#define YYSTYPE char *
map <string,int> varmap;
extern char *yytext;
int lookup(char *);
int yylex(void);
void yyerror (char const *s) {
	fprintf (stderr, "%s\n", s);
}
FILE *out;
int labelcount=0;
string genLabel();
%}

%start lines
%token	NUM ID EQ
%token BINARY_OPERATORS
%token	PLUS	MINUS	TIMES	DIVIDE	
%token SMALLER SMALLEREQ GREATER GREATEREQ EQEQ 
%token IF GOTO
%token LABEL PARAM CALL COMMA LEFTSQPAR RIGSQPAR
%token STAR ANDP  UNARY_OPS PUSH
%%

lines:  /* empty */
        | lines line /* do nothing */ 

line: 	binary  
		| unary 
		| copy 
		|conditional_jump 
		|unconditional_jump 
		|parameters 
		| function_call 
		| indexed_copy
		| address_pointer_assignment 
		| label1
 
binary: 	identifier EQ identifiernum binary_ops identifiernum {
						
						if(strcmp($4,"+")==0)
						{

							int k=lookup($3);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$3);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}

							//pushing into stack first arg
							fprintf(out,"sw $a0 0($sp)\n");
							fprintf(out,"addiu $sp $sp -4\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$5);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}
							fprintf(out,"lw $t1 4($sp)\n");
							fprintf(out,"addiu $sp $sp 4\n");
							fprintf(out,"add $a0 $a0 $t1\n");
							k=lookup($1);
							
							fprintf(out,"sw $a0 %d($t0)\n",4*k - 4);
									
						}else if(strcmp($4,"-")==0){
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$3);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}

							//pushing into stack first arg
							fprintf(out,"sw $a0 0($sp)\n");
							fprintf(out,"addiu $sp $sp -4\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$5);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}
							fprintf(out,"lw $t1 4($sp)\n");
							fprintf(out,"addiu $sp $sp 4\n");
							fprintf(out,"sub $a0 $t1 $a0\n");
							k=lookup($1);
							
							fprintf(out,"sw $a0 %d($t0)\n",4*k - 4);
									
						}else if(strcmp($4,"*")==0){
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$3);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}

							//pushing into stack first arg
							fprintf(out,"sw $a0 0($sp)\n");
							fprintf(out,"addiu $sp $sp -4\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$5);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}
							fprintf(out,"lw $t1 4($sp)\n");
							fprintf(out,"addiu $sp $sp 4\n");
							fprintf(out,"mul $a0 $a0 $t1\n");
							k=lookup($1);
							
							fprintf(out,"sw $a0 %d($t0)\n",4*k - 4);
									
						}else if(strcmp($4,"/")==0){
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$3);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}

							//pushing into stack first arg
							fprintf(out,"sw $a0 0($sp)\n");
							fprintf(out,"addiu $sp $sp -4\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$5);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}
							fprintf(out,"lw $t1 4($sp)\n");
							fprintf(out,"addiu $sp $sp 4\n");
							fprintf(out,"div $a0 $a0 $t1\n");
							k=lookup($1);
							
							fprintf(out,"sw $a0 %d($t0)\n",4*k - 4);
									
						}else if(strcmp($4,"<")==0){
							
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$3);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}

							//pushing into stack first arg
							fprintf(out,"sw $a0 0($sp)\n");
							fprintf(out,"addiu $sp $sp -4\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$5);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}
							fprintf(out,"lw $t1 4($sp)\n");
							fprintf(out,"addiu $sp $sp 4\n");
							fprintf(out,"sub $a0 $a0 $t1\n");

							string l1 = genLabel();
							string l2 = genLabel();

							fprintf(out, "bgtz $a0 %s\n", l1.c_str() );
							fprintf(out, "li $a0 0\n" );
							fprintf(out, "b %s\n",l2.c_str() );
							fprintf(out, "%s:",l1.c_str() );
							fprintf(out, "li $a0 1\n" );
							fprintf(out, "%s:",l2.c_str() );
							k=lookup($1);
							
							fprintf(out,"sw $a0 %d($t0)\n",4*k - 4);
									
						}else if(strcmp($4,">")==0){
							
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$3);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}

							//pushing into stack first arg
							fprintf(out,"sw $a0 0($sp)\n");
							fprintf(out,"addiu $sp $sp -4\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$5);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}
							fprintf(out,"lw $t1 4($sp)\n");
							fprintf(out,"addiu $sp $sp 4\n");
							fprintf(out,"sub $a0 $t1 $a0\n");

							string l1 = genLabel();
							string l2 = genLabel();

							fprintf(out, "bgtz $a0 %s\n", l1.c_str() );
							fprintf(out, "li $a0 0\n" );
							fprintf(out, "b %s\n",l2.c_str() );
							fprintf(out, "%s:",l1.c_str() );
							fprintf(out, "li $a0 1\n" );
							fprintf(out, "%s:",l2.c_str() );
							k=lookup($1);
							
							fprintf(out,"sw $a0 %d($t0)\n",4*k - 4);
									
						}else if(strcmp($4,"==")==0){
							
							int k=lookup($3);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$3);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}

							//pushing into stack first arg
							fprintf(out,"sw $a0 0($sp)\n");
							fprintf(out,"addiu $sp $sp -4\n");


							k=lookup($5);
							if(k==-1)
							{
								fprintf(out,"li $a0 %s\n",$5);
							}
							else
							{
								fprintf(out,"lw $a0 %d($t0)\n",4*k - 4);
							}
							fprintf(out,"lw $t1 4($sp)\n");
							fprintf(out,"addiu $sp $sp 4\n");
							

							string l1 = genLabel();
							string l2 = genLabel();

							fprintf(out, "beq $a0 $t1 %s\n", l1.c_str() );
							fprintf(out, "li $a0 0\n" );
							fprintf(out, "b %s\n",l2.c_str() );
							fprintf(out, "%s:",l1.c_str() );
							fprintf(out, "li $a0 1\n" );
							fprintf(out, "%s:",l2.c_str() );
							k=lookup($1);
							
							fprintf(out,"sw $a0 %d($t0)\n",4*k - 4);
									
						}
					}
			
identifiernum : identifier {$$ = $1;}
				| num {$$ = $1;}

binary_ops: BINARY_OPERATORS { $$ = strdup(yytext); }	

identifier: ID { $$ = strdup(yytext); }

num: 		NUM {$$ = strdup(yytext);}

label : LABEL {$$ = strdup(yytext);}

unary: 		identifier EQ UNARY_OPS identifier {}

copy: 		identifier EQ identifier {
										int k = lookup($3);
										fprintf(out,"lw $a0 %d($t0)\n",4*k-4);
										k = lookup($1);
										fprintf(out,"sw $a0 %d($t0)\n",4*k-4);
									}
			| identifier EQ num 	{
										int k = lookup($1);
										fprintf(out,"li $a0 %s\n",$3);
										fprintf(out,"sw $a0 %d($t0)\n",4*k-4);
									}
label1: label
		{
			fprintf(out,"%s\n",$1);
		}
conditional_jump : IF identifier GOTO label
					 {
					 	//remove : from label:
					 	int l=strlen($4);
					 	$4[l-1]=0;

					 	int k=lookup($2);
					 	fprintf(out,"lw $a0 %d($t0)\n",4*k-4);
				   	 	fprintf(out,"li $t1 0\n");
				   	 	fprintf(out,"bne $a0 $t1 %s\n",$4);
											
					 }
				   | IF num GOTO label 
				   	 {
				   	 	//remove : from label:
				   	 	int l=strlen($4);
					 	$4[l-1]=0;

				   	 	fprintf(out,"li $a0 %s\n",$1);
				   	 	fprintf(out,"li $t1 0\n");
				   	 	fprintf(out,"bne $a0 $t1 %s\n",$4);
				   	 }

unconditional_jump : GOTO label
					 {
					 	//remove : from label:
					 	
					 	int l=strlen($2);
					 	$2[l-1]=0;
					 	fprintf(out,"b %s\n",$2);
					 }

parameters : PUSH identifier 
			| PUSH num {}

function_call : CALL LABEL COMMA num {}
indexed_copy : 	identifier EQ identifier LEFTSQPAR num RIGSQPAR 
				| identifier EQ identifier LEFTSQPAR identifier RIGSQPAR {}

address_pointer_assignment : 	STAR identifier EQ identifier 
								| identifier EQ STAR identifier | identifier EQ ANDP identifier |ANDP identifier EQ identifier | STAR identifier EQ num
								{}
%%
int lookup(char * a)
{
	string x(a);
	if(varmap.find(x)!=varmap.end())return varmap[x];
	else return -1;
}

string genLabel(){
	string l = "_lb";
	stringstream ss;
	ss<<labelcount;
	labelcount++;
	
	return l+ss.str();
}
int main (void) {
	char a[1000];
	out=fopen("mid.txt","r");
	int k=1;
	while(fscanf(out,"%s",a)!=EOF)
	{
		string b(a);
		if(varmap.find(b)==varmap.end()){varmap[b]=k++;}
	}
	fclose(out);
	out=fopen("out.s","w");
	fprintf(out,"main:\n");
	fprintf(out,"move $t0 $sp\n");
	fprintf(out,"addiu $sp $sp %d\n",-4*k );
	yyparse ();
	fprintf(out,"jr $ra\n" );
	fclose(out);
	return 0;
}


int yyerror (char *s) {
	fprintf (stderr, "%s\n", s);
}
