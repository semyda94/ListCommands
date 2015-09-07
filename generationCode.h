#ifndef GENERATIONCODE_H
#define GENERATIONCODE_H

#include "y.tab.h"
#include "clear.h"

void generation_code(struct tree *tree)
{
	if (!tree) return;

	switch (tree->type_node){
		case VIEW:
			count = 0;
			flgView = 0;
			fprintf(out, "In view %s used commands:\n", tree->tree[0]->var);
			memset(tree->tree[0]->var, '\0', strlen(tree->tree[0]->var));
			free(tree->tree[0]->var);
			generation_code(tree->tree[1]);
			break;
		case NAME:
			if(tree->tree[1] == NULL){
				clearStr(tree->tree[0]->var);
				fprintf(out, "%d) %s\n", ++count, tree->tree[0]->var);
			} else {
				int max, i, flgDel = 0, flgCom = 0;

				clearStr(tree->tree[0]->var);
				clearStr(com);
				if (flgView == 0) {
					flgView = 1;
					strcpy(com, "\0");
				} else {

					for ( i = 0; i < strlen(tree->tree[0]->var); i++) {
						if (tree->tree[0]->var[i] == '<'){
							flgDel = i;
							break;
						}
					}
					
					if (flgDel == 0){
						if(strlen(tree->tree[0]->var) >= strlen(com)){
							max = strlen(com);
						} else
							max = strlen(tree->tree[0]->var);

						if (strncmp(com, tree->tree[0]->var, max) != 0  ) {
							clearStr(com);
							fprintf(out, "%d) %s\n", ++count, com);
						}
					} else {
						char help[128];

						for ( i = flgDel; i < strlen(tree->tree[0]->var); i++) {
							help[i - flgDel] = tree->tree[0]->var[i];
						}
						strcat(com, " ");
						strcat(com, help);
					}
				}
				if (flgDel == 0){
					memset(com, '\0', 256);
					strcpy(com, tree->tree[0]->var);
					memset(tree->tree[0]->var, '\0', strlen(tree->tree[0]->var));
					free(tree->tree[0]->var);
					generation_code(tree->tree[1]);
				} else {
					generation_code(tree->tree[1]);
				}
			}
			break;
		default:
			generation_code(tree->tree[0]);
			generation_code(tree->tree[1]);
	}
}

#endif
