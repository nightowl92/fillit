/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:00:03 by stherkil          #+#    #+#             */
/*   Updated: 2019/04/24 22:22:19 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"

#ifndef _FILLIT_H_
#define _FILLIT_H_
typedef struct s_tetr t_tetr;
void			ft_ptab(char **s);
void			ft_ptetr(t_tetr *in);
int				get_tet(t_tetr **tt, int fd, char letter, int i);
int				*solver(t_tetr *in, int size);
int				ft_tabx(char **s);
int				ft_taby(char **s);
int				*getedges(char **s);
struct s_tetr
{
	int index;
	char **s;
	t_tetr *next;
};

#endif
