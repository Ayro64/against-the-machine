#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define GSIZE(o) (sizeof(int) + sizeof(t_som)*(o))
#define room(g,s) (g->lsom[(s)])
#define succ(g,s) (room(g,s)->succ)
#define pred(g,s) (room(g,s)->pred)
#define cost(g,s) (room(g,s)->cost)
#define next(p) ((p)=(p)->next)

typedef struct s_graph *t_graph;
typedef struct s_som   *t_som;
typedef struct s_adj   *t_adj;

t_graph create_graph(int order);
void add_arc(t_graph g, int s, int d, float c);

struct s_som
{
  int	som, cost;
  t_adj	succ, pred;
};

struct s_adj
{
  float	cost;
  int	vsom;
  t_adj	next;
};

struct s_graph
{
  int		order;
  t_som		lsom[1];
};

#endif // MAP_H_INCLUDED
