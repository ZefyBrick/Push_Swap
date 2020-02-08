/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analizator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:35:39 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/25 18:00:41 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_operations(t_swap **list, int result)
{
	while (ft_modul_int(result))
	{
		if (result > 0)
		{
			ft_ra_rb(list, 1);
			result--;
		}
		if (result < 0)
		{
			ft_rra_rrb(list, 1);
			result++;
		}
	}
}

void			ft_minimum(t_swap **list, int i)
{
	int			result;

	while ((*list)->i_por >= i || (*list)->i_por == 0)
		*list = (*list)->next;
	result = (*list)->result;
	*list = (*list)->next;
	while ((*list)->c_por != 0)
	{
		if ((*list)->result != 0 && (*list)->i_por < i \
		&& ft_modul_int((*list)->result) < ft_modul_int(result))
			result = (*list)->result;
		*list = (*list)->next;
	}
	ft_operations(list, result);
}

void			ft_choice(t_swap *list, int max)
{
	int			up;
	int			down;

	up = 0;
	down = 0;
	if (list->c_por == 0)
	{
		list->all = 0;
		list->result = 0;
		return ;
	}
	up = list->c_por;
	down = max - list->c_por + 1;
	if (up >= down)
		list->result = -down;
	else
		list->result = up;
}
