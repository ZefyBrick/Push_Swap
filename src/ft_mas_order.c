/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mas_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:21:55 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 15:18:03 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		cycle(t_swap *list, int i)
{
	t_swap	*tmp;

	tmp = list;
	i = 0;
	while (list)
	{
		list->c_por = i++;
		list = list->next;
		if (tmp == list)
			break ;
	}
}

void		ft_add_number(int *s, t_swap *list)
{
	int		i;
	int		j;

	j = list->prev->c_por;
	i = 0;
	while (i <= j)
	{
		if (s[i] == list->number)
			list->i_por = i++;
		list = list->next;
	}
}

void		ft_order(int *s, t_swap *list, int r)
{
	int		swap;
	int		i;
	int		j;

	i = 0;
	j = list->prev->c_por;
	swap = 0;
	s[i++] = list->number;
	while (list->next->c_por != 0)
	{
		list = list->next;
		s[i++] = list->number;
	}
	i = 0;
	while (i < j)
	{
		if ((s[i] > s[i + 1] && r == 1) || (s[i] < s[i + 1] && r == -1))
		{
			swap = s[i];
			s[i] = s[i + 1];
			s[i + 1] = swap;
			i = -1;
		}
		i++;
	}
}
