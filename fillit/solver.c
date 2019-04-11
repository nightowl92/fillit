/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:04:49 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/06 20:32:46 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	to_corner(char ***s, int *coo)
{
	char **ss;
	int i;
	int j;

	ss = *s;
	i = -1;
	while (++i <= coo[1] - coo[0])
	{
		j = -1;
		while (++j <= coo[3] - coo[2])
		{
			ss[i][j] = ss[coo[0] + i][coo[2] + j];
			ss[coo[0] + i][coo[2] + j] = '.';
		}
	}
	return (0);
}

static char **ft_tabdup(char **s)
{
	char	**out;
	int		i;

	i = 0;
	out = (char**)malloc(sizeof(char*) * 5);
	while (s[i])
	{
		out[i] = ft_strdup(s[i]);
		i++;
	}
	out[i] = NULL;
	return (out);
}

static void ft_tabfree(char ***s)
{
	char **ss;

	ss = *s;
	while (*ss != NULL)
	{
		free(*ss);
		ss++;
	}
	free(*s);
}

static int *ft_try(t_tetr *tet)
{
	char **ss;
	char **cc;
	int i;
	int j;

	i = -1;
	ss = tet->s;
	cc = (tet->next)->s;
	while (ss[++i] != NULL)
	{
		j = -1;
		while (ss[i][++j])
		{
			if (ss[i][j] != '.' && cc[i][j] != '.')
			{
				printf("NOPE");
				return (NULL);
			}
		}
	}
	printf("ORANGE JUICE");
	return (NULL);
}

int *solver(t_tetr *in, int size)
{
	int		*tmp;
	int		*edg;
	t_tetr	*ttr;

	ttr = in;
	while (ttr)
	{
		edg = getedges(ttr->s);
		to_corner(&(ttr->s), edg);
		ft_ptab(ttr->s);
		ttr = ttr->next;
	}
	ft_try(in);
	return (NULL);
}
