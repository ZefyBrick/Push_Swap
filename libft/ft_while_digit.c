/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:29:41 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/15 19:04:39 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_while_digit(char *m)
{
	int		i;

	i = -1;
	while (m[++i] != '\0')
	{
		if ((!ft_isdigit(m[i]) && m[i] != ' ' && m[i] != '-'))
			return (1);
	}
	return (0);
}
