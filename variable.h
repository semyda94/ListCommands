#ifndef VARIABLE_H
#define VARIABLE_H

struct tree *variable(char *name)
{
	struct tree *p;

	p = malloc(sizeof(*p));
	p->var = malloc((sizeof(char) * strlen(name)));
	strcpy(p->var, name);
	p->tree = NULL;
	p->type_node = -1;

	return p;
}

#endif
