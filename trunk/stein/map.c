#include <stdio.h>
#include <stdlib.h>
#include "map.h"

t_graph create_graph(int order)
{
  t_graph	g;
  int		i;

  g = malloc(GSIZE(order));
  g->order = order;
  for (i=0; i<order; i++)
    {
      room(g,i) = malloc(sizeof(struct s_som));
      room(g,i)->som = i;
      room(g,i)->cost = 0;
      succ(g,i) = pred(g,i) = NULL;
    }
  return g;
}

void add_arc(t_graph g, int s, int d, float c)
{
  t_adj		pa;
  pa = malloc(sizeof(struct s_adj));
  pa->cost = c;
  pa->vsom = d;
  pa->next = succ(g,s);
  succ(g,s) = pa;
  pa = malloc(sizeof(struct s_adj));
  pa->cost = c;
  pa->vsom = s;
  pa->next = pred(g,d);
  pred(g,d) = pa;
}
