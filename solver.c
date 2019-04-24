/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:04:49 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/24 23:48:44 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int to_corner(char ***s, int *coo)
{
	char **ss;
	int i;
	int j;

	ss = *s;
	i = -1;
	if (coo[0] == 0 && coo[2] == 0)
		return (0);
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
	char **out;
	int i;

	i = 0;
	out = (char **)malloc(sizeof(char *) * 5);
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

static void ttr_tocorner(t_tetr *ttr)
{
	int *tmp;
	int *edg;

	while (ttr)
	{
		edg = getedges(ttr->s);
		to_corner(&(ttr->s), edg);
		ttr = ttr->next;
	}
}

static int matchcheck(char **s1, char **s2, int a, int b)
{
	int i;
	int j;
	int *coo;
	int dim1;
	int dim2;

	dim1 = ft_tabx(s1);
	dim2 = ft_taby(s1);
	coo = getedges(s2);
	i = -1;
	while (++i <= coo[1])
	{
		j = -1;
		if (a + i >= dim1)
			break ;
		while (++j <= coo[3])
		{
			if (b + j >= dim2)
				break;
			else if (s1[a + i][b + j] != '.' && s2[i][j] != '.')
				return (0);
		}
	}
	return (1);
}
/*
static int *bestfit()
	{

	}
*/
int *solver(t_tetr *in, int size)
{
	int *tmp;
	int *edg;

	ft_ptetr(in);
	write(1, "\n", 1);
	ttr_tocorner(in);
	ft_ptetr(in);
	ft_ptab(in->s);
	ft_ptab(in->next->s);
	printf("match check is %d\n", matchcheck(in->s, in->next->s, 5, 0));
	return (NULL);
}