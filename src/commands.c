/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:57:26 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/26 17:18:33 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sa_sb(t_swap *list, int i)
{
	int			swap;

	swap = 0;
	if (list->next != NULL && list->next != list)
	{
		swap = list->number;
		list->number = list->next->number;
		list->next->number = swap;
		swap = list->i_por;
		list->i_por = list->next->i_por;
		list->next->i_por = swap;
		swap = list->all;
		list->all = list->next->all;
		list->next->all = swap;
		swap = list->result;
		list->result = list->next->result;
		list->next->result = swap;
		if (i == 1)
			write(1, "sa\n", 3);
		if (i == 2)
			write(1, "sb\n", 3);
		if (i == 3)
			write(1, "ss\n", 3);
	}
}

void			ft_pa_pb_end(t_swap **one, t_swap **two)
{
	(*one)->prev->next = (*one)->next;
	(*one)->next->prev = (*one)->prev;
	if ((*two)->prev == NULL)
	{
		free(*two);
		*two = *one;
		(*two)->prev = *one;
		(*two)->next = *one;
	}
	else
	{
		(*one)->next = *two;
		(*one)->prev = (*two)->prev;
		(*two)->prev->next = *one;
		(*two)->prev = *one;
		*two = (*one);
	}
}

void			ft_pa_pb(t_swap **one, t_swap **two, int i)
{
	t_swap		*tmp;

	if ((*one)->next != NULL && (*one)->next != (*two)->next)
	{
		tmp = (*one)->next;
		ft_pa_pb_end(one, two);
		if (*one == tmp)
		{
			if (!(*one = (t_swap *)malloc(sizeof(t_swap))))
				exit(0);
			(*one)->next = NULL;
			(*one)->prev = NULL;
		}
		else
		{
			*one = tmp;
			cycle(*one, -1);
		}
		cycle(*two, 1);
		if (i == 1)
			write(1, "pa\n", 3);
		if (i == 2)
			write(1, "pb\n", 3);
	}
}

void			ft_ra_rb(t_swap **list, int i)
{
	if ((*list)->next != NULL && (*list)->next != *list)
	{
		*list = (*list)->next;
		if (i == 1)
			write(1, "ra\n", 3);
		if (i == 2)
			write(1, "rb\n", 3);
		if (i == 3)
			write(1, "rr\n", 3);
		cycle(*list, -1);
	}
}

void			ft_rra_rrb(t_swap **list, int i)
{
	if ((*list)->prev)
	{
		*list = (*list)->prev;
		if (i == 1)
			write(1, "rra\n", 4);
		if (i == 2)
			write(1, "rrb\n", 4);
		if (i == 3)
			write(1, "rrr\n", 4);
		cycle(*list, 1);
	}
}
