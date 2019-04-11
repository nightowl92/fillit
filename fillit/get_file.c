/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:30:45 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/05 22:33:11 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_strappend(char **s1, char *s2)
{
	char *tmp;

	if (!*s1)
	{
		if (!(tmp = ft_strdup(s2)))
			return (0);
	}
	else
	{
		if (!(tmp = ft_strjoin(*s1, s2)))
			return (0);
	}
	if (*s1 && s1)
		free(*s1);
	*s1 = tmp;
	return (1);
}

static void ft_replace(char **s, char ch)
{
	int i;

	i = 0;
	while ((*s)[i])
	{
		if ((*s)[i] == '#')
			(*s)[i] = ch;
		i++;
	}
}

int			get_tet(t_tetr **tt, int fd, char letter, int i)
{
	char	*str;
	char	*s2;
	int		ret;
	t_tetr	*new;

	new = malloc(sizeof(t_tetr));
	s2 = NULL;
	while ((ret = gnl(fd, &str)))
	{
		ft_strappend(&s2, str);
		ft_strappend(&s2, "\n");
		if (str[0] == 0)
			break ;
	}
	ft_replace(&s2, letter);
	if (!(new->s = ft_strsplit(s2, '\n')))
	{
		free(new);
		return (0);
	}
	new->index = i;
	new->next = *tt;
	*tt = new;
	return (1);
}
