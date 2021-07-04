/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:54:31 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/14 13:02:28 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	size_t	total;
	size_t	i;

	total = count * size;
	if (!(dest = malloc(total)))
		return (NULL);
	i = 0;
	while (total--)
	{
		dest[i] = 0;
		i++;
	}
	return ((void *)dest);
}
