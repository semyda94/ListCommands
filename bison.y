%{
	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>

	#include "generalData.h"
	#include "variable.h"
	#include "createNode.h"
	#include "generationCode.h"
	#include "clear.h"

	void yyerror(const char *);
	int yylex(void);
%}

%union {
	char *name_id;
	struct tree *nptr;
}

%token VIEW
%token <name_id> NAME
%type <nptr> view command
%%


program:	function
			| /* NULL */
			;

function:	program view 			{ generation_code($2); }
			;

view:		VIEW ':' NAME command	{ $$ = create_node(VIEW, 2, variable($3), $4, NULL, NULL); }
			;
command:	NAME						{ $$ = create_node(NAME, 1, variable($1), NULL, NULL, NULL); }
			|NAME command			{ $$ = create_node(NAME, 2, variable($1), $2, NULL, NULL); }
			;
%%

int main(int argc, char *argv[])
{
	if(argc < 2){
		perror("Input file not!!!\n");
		return -1;
	}
	
	char *name = clear(argv[1]);
	yyin = fopen(name, "r");
	if(!yyin) {
		perror(name);
		return -1;
	}

	printf("FILE_OUT: DOC\n");
	out = fopen("DOC", "w+");
	if(!out) {
		perror("DOC");
		return -1;
	}

	while (!feof(yyin))
		yyparse();

	fclose(yyin);
	fclose(out);
	return 0;
}

void yyerror(const char *s)
{
	fprintf(stderr, "line %d: %s\n", line, s);
	exit(0);
}
