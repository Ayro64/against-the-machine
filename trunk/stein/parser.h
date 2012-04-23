#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#define NB_MAX_CHAR 80
#include "map.h"

extern t_graph g;
extern char* buffer;

void parseTextFile(char *path);
void treatLine(char a);

#endif // PARSER_H_INCLUDED
