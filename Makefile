all: start

start : OutputCommands
		./OutputCommands commands_dump

OutputCommands: lex.yy.c y.tab.h
		gcc lex.yy.c y.tab.c -g -o OutputCommands -std=c89

lex.yy.c: flex.l
		flex flex.l
y.tab.h: bison.y variable.h generalData.h createNode.h generationCode.h clear.h
		bison -dy bison.y
