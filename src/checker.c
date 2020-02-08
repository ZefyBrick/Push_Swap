/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:55:17 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 16:10:04 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_compare(t_swap *list, t_swap *b)
{
	t_swap	*tmp;

	tmp = list;
	if (b->next != NULL || list->i_por != list->c_por || list->next == NULL)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	list = list->next;
	while (list != tmp)
	{
		if (list->i_por != list->c_por)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		list = list->next;
	}
	write(1, "OK\n", 3);
}

void			execution_end(t_swap **a, t_swap **b, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_ra_rb(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_ra_rb(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_ra_rb(a, 0);
		ft_ra_rb(b, 0);
	}
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra_rrb(a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rra_rrb(b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_rra_rrb(a, 0);
		ft_rra_rrb(b, 0);
	}
	else
		error();
}

void			execution(t_swap **a, t_swap **b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa_sb(*a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sa_sb(*b, 0);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_sa_sb(*a, 0);
		ft_sa_sb(*b, 0);
	}
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa_pb(b, a, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pa_pb(a, b, 0);
	else
		execution_end(a, b, line);
}

void			gnl_executor(t_swap **psa, t_swap **psb, char *line, char *av)
{
	execution(psa, psb, line);
	if (!(ft_strcmp(av, "-v")))
	{
		vizualization(*psa, psb);
		write(1, "\norder: ", 8);
		cyan();
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
	}
	free(line);
}

int				main(int ac, char **av)
{
	char		*line;
	t_swap		*a;
	t_swap		*b;
	int			*s;

	if (!(b = (t_swap *)malloc(sizeof(t_swap))))
		exit(0);
	b->next = NULL;
	b->prev = NULL;
	if (ac > 1)
	{
		ft_reading(ac, av, &a);
		if (!(s = (int *)malloc(sizeof(int) * (a->prev->c_por + 1))))
			exit(0);
		ft_order(s, a, 1);
		ft_add_number(s, a);
		while (get_next_line(0, &line) > 0)
			gnl_executor(&a, &b, line, av[1]);
		ft_compare(a, b);
	}
	exit(0);
}
