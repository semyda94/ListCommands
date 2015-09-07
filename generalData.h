#ifndef GENERALDATA_H
#define GENERALDATA_H

#define YYERROR_VERBOSE 1

FILE *yyin;
FILE *out;

struct tree{
	int type_node;
	char *var;
	int count;
	struct tree **tree;
};


char com[256];
int count;
int flgView;
extern int line;

#endif
