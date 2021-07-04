/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:56:50 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/08 18:34:12 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

size_t		ft_double_strlen(const char **str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
