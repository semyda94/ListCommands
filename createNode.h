#ifndef CREATENODE_H
#define CREATENODE_H

struct tree *create_node(int type, int count, struct tree *node1, struct tree *node2, struct tree *node3, struct tree *node4)
{
	struct tree *p;
	
	p = malloc(sizeof(*p));

	p->type_node = type;
	p->count = count;
	p->tree = malloc(sizeof(struct tree) * count);
	if (count == 1)
		p->tree[0] = node1;
	else if (count == 2) {
		p->tree[0] = node1;
		p->tree[1] = node2;
	} else if (count == 3) {
		p->tree[0] = node1;
		p->tree[1] = node2;
		p->tree[2] = node3;
	} else if (count == 4) {
		p->tree[0] = node1;
		p->tree[1] = node2;
		p->tree[2] = node3;
		p->tree[3] = node4;
	}

	return p;
}

#endif
