#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "map.h"

void treatCommand(char a);
void path_cost(int hp, char* arg);
void putInList(int num, t_adj *list);
int listSize(t_adj list);
void revert(int *numrooms, t_adj list);
void testPath(int *list, int hp);

#endif // MAIN_H_INCLUDED
