/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:41:14 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 16:11:55 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			vizualization(t_swap *psa, t_swap **psb)
{
	t_swap		*a;
	t_swap		*b;

	a = psa;
	b = (*psb);
	usleep(100000);
	system("clear");
	cyan();
	write(1, "\n A \t B \n", 9);
	reset();
	if (psa->next != NULL)
		only_a(&psa);
	while (psa->c_por != 0 && psa->next != NULL)
		only_a(&psa);
	if (*psb && (*psb)->next != NULL)
		only_b(psb);
	while ((*psb)->c_por != 0 && (*psb)->next != NULL)
		only_b(psb);
}

void			only_a(t_swap **a)
{
	green();
	write(1, "[", 1);
	reset();
	ft_putnbr((*a)->i_por);
	green();
	write(1, "]\t", 2);
	reset();
	write(1, "[ ]\n", 4);
	(*a) = (*a)->next;
}

void			only_b(t_swap **b)
{
	reset();
	write(1, "[ ]\t", 4);
	green();
	write(1, "[", 1);
	reset();
	ft_putnbr((*b)->i_por);
	green();
	write(1, "]\n", 2);
	reset();
	(*b) = (*b)->next;
}

void			end_of_vizualization(int c_por)
{
	write(1, "num of c_pors: ", 15);
	cyan();
	ft_putnbr(c_por);
	write(1, "\n", 1);
}
