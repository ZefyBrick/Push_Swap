/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:58:47 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 17:00:50 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_colvo_operations(t_swap **list, t_swap **ochek, int i, int turn)
{
	int			iter;
	int			max;

	iter = 0;
	max = (*list)->prev->c_por;
	if ((*list)->i_por < i && (*list)->i_por != 0)
	{
		ft_choice(*list, max);
		(*list)->turn = turn;
		++iter;
	}
	while ((*list)->next->c_por != 0)
	{
		*list = (*list)->next;
		if ((*list)->i_por < i && (*list)->i_por != 0)
		{
			ft_choice(*list, max);
			(*list)->turn = turn;
			++iter;
		}
	}
	ft_minimum(list, i);
	ft_pa_pb(list, ochek, 2);
	if (iter > 1)
		ft_colvo_operations(list, ochek, i, turn);
}

void		ft_free_list(t_swap *list)
{
	ft_null_list(list);
	list = list->next;
	while (list->c_por != 0)
	{
		ft_null_list(list);
		list = list->next;
	}
}

void		ft_push(t_swap *a, t_swap *b, int turn)
{
	while (a->prev->c_por > 2)
	{
		turn++;
		ft_colvo_operations(&a, &b, ft_average(a), turn);
	}
	ft_sort_a_3(&a);
	ft_free_list(a);
	ft_free_list(b);
	turn = b->turn + 1;
	while (--turn)
		ft_push_in_a(&a, &b, turn);
	if (a->i_por < a->prev->c_por / 2)
	{
		while (a->i_por != 0)
			ft_rra_rrb(&a, 1);
	}
	else
	{
		while (a->i_por != 0)
			ft_ra_rb(&a, 1);
	}
	free(b);
}

int			main(int ac, char **av)
{
	t_swap		*a;
	t_swap		*b;
	int			*s;
	int			turn;

	turn = 0;
	if (!(b = (t_swap *)malloc(sizeof(t_swap))))
		exit(0);
	b->next = NULL;
	b->prev = NULL;
	if (ac > 1)
	{
		ft_reading(ac, av, &a);
		if (!(s = (int *)malloc(sizeof(int) * (a->prev->c_por + 2))))
			exit(0);
		ft_order(s, a, 1);
		ft_add_number(s, a);
		ft_sort_or_not_sort(a);
		if (a->prev->c_por >= 5)
			ft_push(a, b, turn);
		else
			ft_push_min(a, b);
	}
	exit(0);
}
