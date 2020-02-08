/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:16:15 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 17:52:05 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_chose_b(t_swap *list, int max)
{
	int down;
	int	up;

	up = list->c_por;
	down = max - list->c_por + 1;
	if (up <= down)
		list->result = up;
	else
		list->result = -down;
}

void		ft_what_operations(t_swap **a, t_swap **b)
{
	(*b)->all = ft_chosen_a(*a, (*b)->i_por);
	ALL_B = ft_chosen_a(*a, (*b)->i_por);
	if (((ALL_B >= 0 && RES_B >= 0) || (ALL_B <= 0 && RES_B <= 0)) \
	&& ALL_B_M >= RES_B_M)
		OP_B = ALL_B;
	else if (((ALL_B >= 0 && RES_B >= 0) || (ALL_B <= 0 && RES_B <= 0)) \
	&& ALL_B_M <= RES_B_M)
		OP_B = RES_B;
	else if (((ALL_B >= 0 && RES_B <= 0) || (ALL_B <= 0 && RES_B >= 0)))
		OP_B = RES_B - ALL_B;
}

void		ft_list_parametrs(t_min *min, t_swap **b)
{
	min->operations = OP_B;
	min->min_res = RES_B;
	min->all = ALL_B;
}

void		ft_null_list(t_swap *list)
{
	list->all = 0;
	list->operations = 0;
	list->result = 0;
}

void		ft_variables(t_min *min, t_swap *b)
{
	min->iter = 0;
	min->operations = 2147483647;
	min->min_res = 0;
	min->all = 0;
	min->max = b->prev->c_por;
}
