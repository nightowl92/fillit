/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:11:03 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/20 15:55:43 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//void 
void newtab(char ***s, int size)
{
	int i;

	i = -1;
	*s = (char**)malloc(sizeof(char*) * size + 1);
	while (++i < size)
	{
		(*s)[i] = (char*)malloc((sizeof(char) * size + 1));
		ft_memset((*s)[i], '.', size - 1);
		(*s)[i][size - 1] = '\0';
	}
	(*s)[size] = NULL;
}

int checktab(char **s, char in[4][4], int n, int m, int max2)
{
	int i;
	int j;
	int max1;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i + n][j + m] != '.' && in[i][j] != '.')
				return (0);
			if (s[i + n][j + m] == '.')
			{	
				if (i + n > j + m)
					max1 = i + n;
				else
					max1 = j + m;
				if (max1 > max2)
					return (0);
			}
		}
	}
	return (1);
}

char **addtab(char **s, char in[4][4], int n, int m)
{
	int i;
	int j;
	int max;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i + n][j + m] == '.')
			{
				s[i + n][j + m] = in[i][j];
				if (i + n > j + m)
					max = i + n;
				else
					max = j + m;
			}
		}
	}
	return (s);
}

int fit(char **s, char ttr[4][4], int n)
{
	int i;
	int j;
		i = -1;
		while (++i < 6)
		{
			j= -1;
			while (++j < 6)
				if (checktab(s, ttr,i, j, n))
				{
					addtab(s, ttr,i,j);
					return (1);
				}
		}
	return (0);
}

int backtrack(char tetris[28][4][4], char ***s, int *list, int max)
{
	/*
	int i;
	int ret;
	int keep;

i = -1;
while ((ret = get_next(list)) != 0)
{
	
}
fit(*s, tetris[0],max);
list[0] = 0;
backtrack(tetris, s, list, max);
*/
/*
	   i = -1;
	   while ((ret = list_match(s, list, ++i, max)) != -1)
	   {
	   if (ret != 0)
	   {
	   list[i] = 0;
	   if ((tmp = backtrack(tetris, putin(tetris[i], s, max), list, max)))
	   return tmp;
	   list[i] = i;
	   }*/
	return (0);
}

int ft_try(char tetris[28][4][4], int len, char ***s)
{
	int		i;
	int		max;
	int		*list;
	char **tmp;

	list = (int*)malloc(sizeof(int) * (len + 1));
	i = -1;
	while (++i < len)
		list[i] = i;
	i = -1;
	while (++i < len)
		printf("%d\n",list[i]);
	list[++i] = -1;
	newtab(s, len * 2);
	backtrack(tetris, s, list, 4);
	/*
	   while (!(s = backtrack(tetris, s, list, len, max)))
	   ++max;*/
	//addtab(*s, tetris[0],0,0);
	return (4);
}
