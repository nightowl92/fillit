#include "fillit.h"

static void ft_pstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}

}

void ft_ptab(char **s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_pstr(*s);
		write(1,"\n",1);
		s++;
	}
}

int		main(int ac, char **av)
{
	int fd;
	t_tetr *ok;
	char **ss;
	int *out;
	int i;

	fd = open(av[1],O_RDONLY);
	i = 0;
	get_tet(&ok, fd,'A', i);
	i = 1;
	get_tet(&ok, fd,'B', i);

	solver(ok, i + 1);

	//printf("%d %d %d %d",out[0],out[1],out[2],out[3]);
	return (0);
}
