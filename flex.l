%option noyywrap yylineno
%{
	#include "y.tab.h"
	int line = 1;
%}

letter [a-zA-Z]
digit [0-9]
delim [,.-_()+*/{};:]

%%

({letter}|{digit}|"!"|"+"|"-"|"_"|" "|"<"|">"|"."|"/")*	{
	if (strcmp(yytext, "VIEW") == 0)
		return VIEW;
	else {
		yylval.name_id = strdup(yytext);
		return NAME;
	}
}

({delim}|"\"") { return *yytext; }

[ \t\r] ;

("=")*	;

[\n] { line +=1; }

. { yyerror(yytext); }

%%
