/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:33:11 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/27 16:18:40 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void			ft_repeat(t_swap **list, t_swap *tmp)
{
	int		i;
	t_swap	*d;

	d = *list;
	i = (*list)->number;
	if (*list != tmp)
	{
		while (*list != tmp)
		{
			if (i == (*list)->prev->number)
				error();
			*list = (*list)->prev;
		}
		*list = d;
	}
}

void			ft_filling(char *av, t_swap **list, t_swap **d, t_swap *tmp)
{
	static int		j;

	if (!j)
		j = 0;
	while (*av)
	{
		if (ft_while_digit(av))
			error();
		if (*av)
		{
			(*list)->number = ft_atoi(av);
			ft_repeat(list, tmp);
			if (!((*list)->next = (t_swap *)malloc(sizeof(t_swap))))
				exit(0);
			(*list)->c_por = j++;
			ft_null_list(*list);
			av = av + ft_len_digit((*list)->number, 10);
			while (*av == ' ')
				av = av + 1;
			*list = (*list)->next;
			(*list)->prev = *d;
			*d = *list;
		}
	}
}

void			ft_av(int j, char *av)
{
	j = -1;
	while (av[++j] != '\0')
		if (av[j] == '-' && (!(ft_strchr("123456789", av[j + 1]))
		|| av[j - 1] != ' '))
			error();
	if (!ft_strcmp(av, ""))
		error();
}

int				ft_reading(int ac, char *av[], t_swap **list)
{
	t_swap		*d;
	t_swap		*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(*list = (t_swap *)malloc(sizeof(t_swap))))
		exit(0);
	ft_null_list(*list);
	tmp = *list;
	d = *list;
	if (!(ft_strcmp(av[1], "-v")))
		i++;
	while (++i < ac)
	{
		ft_av(j, av[i]);
		ft_filling(av[i], list, &d, tmp);
	}
	tmp->prev = (*list)->prev;
	(*list)->prev->next = tmp;
	free(*list);
	*list = tmp;
	return (0);
}
