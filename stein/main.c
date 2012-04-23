#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "map.h"
#include "parser.h"

t_graph g;
char *buffer;


int main(int ac, char **args)
{
    parseTextFile(args[1]);
    buffer = malloc(NB_MAX_CHAR);
    do
    {
        fgets(buffer, NB_MAX_CHAR, stdin);
        puts(buffer);
        if(!feof(stdin))
            treatCommand(buffer[0]);
    }while(!feof(stdin));

    free(buffer);
    return 0;
}

void treatCommand(char a)
{
    char *param2, *temp=buffer;
    int i=0, param1=0;
    param2 = malloc(NB_MAX_CHAR);
    switch(a)
    {
        case('C'):
            for(;*temp && *temp != ' ';++temp){}
            temp++;
            for(;*temp != ' ';temp++)
            {
                param1 = param1*10 + (*temp - 48);
                i++;
            }
            for(;*temp;temp++)
            {
                param2[i] = *temp;
                i++;
            }
            path_cost(param1, param2);
            break;
        case('M'):
            for(;*temp && *temp != ' ';++temp){}
            temp++;
            for(;*temp != ' ';temp++)
            {
                param2[i] = *temp;
                i++;
            }
            temp++;
            for(;*temp;temp++)
            {
                param1 = param1*10 + (*temp - 48);
            }
            //g->lsom[param1-1]->cost = -param2;
            break;
        default:
            break;
    }
    free(param2);
}

void path_cost(int hp, char *path)
{
    int cur=0;
    t_adj sumList = NULL;
    int *roomorder;
    path++;
    for(;*path != '\n' && *path != ']';path++)
    {
        for(;*path != '\n' && *path != ';' && *path != ']';path++)
        {
            if(*path != ']')
                cur = 10*cur + (*path - 48);
        }
        putInList(cur, &sumList);
        printf("%d\n", sumList->vsom);
        cur=0;
    }
    roomorder = malloc(listSize(sumList));
    revert(roomorder, sumList);
    free(roomorder);
}

void putInList(int num, t_adj *list)
{
    t_adj L = malloc(sizeof(struct s_adj));

    L->vsom = num;
    L->cost = 0;
    L->next = *list;
    *list = L;
}

int listSize(t_adj list)
{
    int i = 0;
    while(list)
    {
        i++;
        list = list->next;
    }
    return i;
}

void revert(int *numrooms, t_adj list)
{
    int i = listSize(list);
    while (list)
    {
        numrooms[i-1] = list->vsom;
        list = list->next;
        i--;
    }
}

//t_adj searchList(t_adj where, int what)
//{
//    while(where && what != where->vsom)
//    {
//
//    }
//}

//void testPath(int *list, int hp)
//{
//    hp = hp + g->lsom[list[0]-1]->succ[]->cost;
//
//    while(list->next)
//    {
//        hp = hp + g->lsom[list->vsom-1]->succ[*list->next->vsom-1]->cost;
//        hp = hp + g->lsom[*list->vsom]->cost;
//    }
//}
