/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 01:52:26 by olga              #+#    #+#             */
/*   Updated: 2019/09/27 17:53:00 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_operations_3(t_swap **b, int all, int result, t_swap **a)
{
	while (ft_modul_int(result))
	{
		if (result > 0)
			ft_ra_rb(b, 2);
		else if (result < 0)
			ft_rra_rrb(b, 2);
		result = ft_modul_int_change(result, -1);
	}
	while (ft_modul_int(all))
	{
		if (all > 0)
			ft_ra_rb(a, 1);
		else if (all < 0)
			ft_rra_rrb(a, 1);
		all = ft_modul_int_change(all, -1);
	}
}

void			ft_operations_2(t_swap **b, int all, int result, t_swap **a)
{
	while (ft_modul_int(all))
	{
		if (all > 0)
		{
			ft_ra_rb(a, 0);
			ft_ra_rb(b, 3);
		}
		else if (all < 0)
		{
			ft_rra_rrb(a, 0);
			ft_rra_rrb(b, 3);
		}
		result = ft_modul_int_change(result, -1);
		all = ft_modul_int_change(all, -1);
	}
	while (ft_modul_int(result))
	{
		if (result > 0)
			ft_ra_rb(b, 2);
		else if (result < 0)
			ft_rra_rrb(b, 2);
		result = ft_modul_int_change(result, -1);
	}
}

void			ft_operations_1(t_swap **b, int all, int result, t_swap **a)
{
	while (ft_modul_int(result))
	{
		if (result > 0)
		{
			ft_ra_rb(a, 0);
			ft_ra_rb(b, 3);
		}
		else if (result < 0)
		{
			ft_rra_rrb(a, 0);
			ft_rra_rrb(b, 3);
		}
		result = ft_modul_int_change(result, -1);
		all = ft_modul_int_change(all, -1);
	}
	while (ft_modul_int(all) > 0)
	{
		if (all > 0)
			ft_ra_rb(a, 1);
		else if (all < 0)
			ft_rra_rrb(a, 1);
		all = ft_modul_int_change(all, -1);
	}
}

void			ft_operations_b(t_swap **b, t_min *min, t_swap **a)
{
	if ((min->all >= 0 && min->min_res >= 0) \
	|| (min->all <= 0 && min->min_res <= 0))
	{
		if (ft_modul_int(min->all) >= ft_modul_int(min->min_res))
			ft_operations_1(b, min->all, min->min_res, a);
		else
			ft_operations_2(b, min->all, min->min_res, a);
	}
	else
		ft_operations_3(b, min->all, min->min_res, a);
}
