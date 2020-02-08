/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:30:38 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 17:51:44 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sort_or_not_sort(t_swap *a)
{
	t_swap	*tmp;

	tmp = a;
	if (a->i_por != a->c_por)
		return ;
	a = a->next;
	while (a != tmp)
	{
		if (a->i_por != a->c_por)
			return ;
		a = a->next;
	}
	exit(0);
}

int					ft_average(t_swap *a)
{
	int		j;

	j = a->i_por;
	a = a->next;
	while (a->c_por != 0)
	{
		j += a->i_por;
		a = a->next;
	}
	j /= a->prev->c_por;
	return (j);
}

void				ft_sort_a_min(t_swap **a)
{
	if ((*a)->i_por < (*a)->next->i_por)
	{
		if ((*a)->next->i_por < (*a)->prev->i_por)
			return ;
		else
		{
			ft_rra_rrb(a, 1);
			if ((*a)->i_por > (*a)->next->i_por)
				ft_sa_sb(*a, 1);
		}
	}
	else
	{
		if ((*a)->i_por < (*a)->prev->i_por)
			ft_sa_sb(*a, 1);
		else
		{
			ft_ra_rb(a, 1);
			if ((*a)->i_por > (*a)->next->i_por)
				ft_sa_sb(*a, 1);
		}
	}
}

void				ft_look_up_x(t_swap **a, t_swap **b, int i)
{
	int		max;
	t_swap	*tmp;

	tmp = *a;
	max = (*a)->prev->c_por;
	if ((*a)->i_por == i)
	{
		ft_chose_b(*a, max);
		ft_operations(&tmp, (*a)->result);
		ft_pa_pb(&tmp, b, 2);
		*a = tmp;
		return ;
	}
	while ((*a)->next->c_por != 0)
	{
		*a = (*a)->next;
		if ((*a)->i_por == i)
		{
			ft_chose_b(*a, max);
			ft_operations(&tmp, (*a)->result);
			ft_pa_pb(&tmp, b, 2);
			*a = tmp;
			return ;
		}
	}
}

void				ft_push_min(t_swap *a, t_swap *b)
{
	if (a->prev->c_por == 1)
	{
		if (a->number > a->next->number)
			ft_sa_sb(a, 1);
		exit(0);
	}
	else
	{
		if (a->prev->c_por > 2)
		{
			ft_look_up_x(&a, &b, 0);
			if ((a)->prev->c_por == 3)
				ft_look_up_x(&a, &b, 1);
		}
		ft_sort_a_min(&a);
		if (b->next != NULL && b->number < b->next->number)
			ft_sa_sb(b, 2);
		while (b->next != NULL)
			ft_pa_pb(&b, &a, 1);
	}
}
