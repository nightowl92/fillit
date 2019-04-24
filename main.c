/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:59:52 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/24 22:31:33 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_tabx(char **s)
{
	int i;

	i = -1;
	while (s[++i] != NULL)
		;
	return (i);
}

int ft_taby(char **s)
{
	int j;

	j = -1;
	while (s[0][++j])
		;
	return (j);
}

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
		return;
	while (*s)
	{
		ft_pstr(*s);
		write(1, "\n", 1);
		s++;
	}
}

void ft_ptetr(t_tetr *in)
{
	while (in)
	{
		ft_ptab(in->s);
		in = in->next;
	}
}
int main(int ac, char **av)
{
	int fd;
	t_tetr *ok;
	char **ss;
	int *out;
	int i;

	fd = open(av[1], O_RDONLY);
	i = 0;
	
	get_tet(&ok, fd, 'A', i);

	i = 1;
	get_tet(&ok, fd, 'B', i);
	i = 2;
	get_tet(&ok, fd, 'C', i);
	i = 3;
	get_tet(&ok, fd, 'D', i);

	solver(ok, i + 1);

	return (0);
}
