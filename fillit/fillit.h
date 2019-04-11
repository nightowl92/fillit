#include "GNL/get_next_line.h"

#ifndef _FILLIT_H_
#define _FILLIT_H_
typedef struct	s_tetr t_tetr;
void			ft_ptab(char **s);
int				get_tet(t_tetr **tt, int fd, char letter, int i);
int				*solver(t_tetr *in, int size);
int				*getedges(char **s);
struct			s_tetr
{
	int		index;
	char	**s;
	t_tetr	*next;
};

#endif
