/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 07:08:35 by olga              #+#    #+#             */
/*   Updated: 2019/09/27 18:24:19 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_chosen_a(t_swap *a, int i_por)
{
	int		max;

	max = a->prev->c_por;
	while (1)
	{
		if (a->i_por == i_por + 1)
		{
			ft_chose_b(a, max);
			return (a->result);
		}
		a = a->next;
		while (a->c_por != 0)
		{
			if (a->i_por == i_por + 1)
			{
				ft_chose_b(a, max);
				return (a->result);
			}
			a = a->next;
		}
		++i_por;
	}
	return (0);
}

void		ft_big_b(t_swap **a, t_swap **b, t_min *min)
{
	ft_chose_b(*b, min->max);
	ft_what_operations(a, b);
	++min->iter;
}

void		ft_push_in_a1(t_swap **a, t_swap **b, t_min *min, int turn)
{
	ft_variables(min, *b);
	if ((*b)->turn == turn)
	{
		ft_big_b(a, b, min);
		ft_list_parametrs(min, b);
	}
	*b = (*b)->next;
	while ((*b)->c_por != 0)
	{
		if ((*b)->turn == turn)
		{
			ft_big_b(a, b, min);
			if (OP_B_M < OP_M)
				ft_list_parametrs(min, b);
		}
		*b = (*b)->next;
	}
	ft_operations_b(b, min, a);
	ft_pa_pb(b, a, 1);
}

void		ft_push_in_a(t_swap **a, t_swap **b, int turn)
{
	t_min	*min;

	if (!(min = (t_min *)malloc(sizeof(t_min))))
		exit(0);
	min->iter = 2;
	while (min->iter > 1)
		ft_push_in_a1(a, b, min, turn);
	free(min);
}

void		ft_sort_a_3(t_swap **a)
{
	if ((*a)->i_por < (*a)->next->i_por)
	{
		if ((*a)->i_por > (*a)->prev->i_por)
			return ;
		else
		{
			ft_ra_rb(a, 1);
			if ((*a)->i_por > (*a)->next->i_por)
				ft_sa_sb(*a, 1);
		}
	}
	else
	{
		if ((*a)->next->i_por > (*a)->prev->i_por)
			ft_sa_sb(*a, 1);
		else
		{
			ft_rra_rrb(a, 1);
			if ((*a)->i_por > (*a)->next->i_por)
				ft_sa_sb(*a, 1);
		}
	}
}
