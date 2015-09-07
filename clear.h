#ifndef CLEAR_H
#define CLEAR_H

char *clear(char *nameFile)
{
	FILE *in;
	FILE *help;
	int c,count;
	char *helpFile;

	helpFile = malloc(sizeof(char) * (sizeof(nameFile) + 5));

	strcpy(helpFile, nameFile);
	strcat(helpFile, "_help");
	printf("Create help file: %s\n", helpFile);

	in = fopen(nameFile, "r");
	if (!in) {
		perror(nameFile);
		return NULL;
	}

	help = fopen(helpFile, "w");
	if (!help) {
		perror(helpFile);
		return NULL;
	}

	count = 0;
	while (count < 4 && c != EOF) {
		c = getc(in);
		if (c == '\n')
			count++;
	}

	while ((c = getc(in)) != EOF)
		if (c!=13 & c !=27)
			fprintf(help, "%c", c);

	fclose(in);
	fclose(help);

	return helpFile;
}

void clearStr(char *var)
{
	char *helpStr;
	int i;
	helpStr = malloc(sizeof(char) * strlen(var));
	for (i = 0; i < strlen(var); i++)
		if (var[i] > 31 && var[i] < 127)
			helpStr[i] = var[i];
	strcpy(var, helpStr);
}
#endif
