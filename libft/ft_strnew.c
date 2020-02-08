/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:19:05 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/09 12:35:41 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	if (!(c = (char*)malloc(sizeof(char) * size + 1)))
		exit(0);
	while (i < size + 1)
	{
		c[i] = '\0';
		i++;
	}
	return (c);
}
