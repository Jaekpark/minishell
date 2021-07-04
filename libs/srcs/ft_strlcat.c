/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:27:50 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/08 14:39:43 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;
	size_t	dstsize;
	size_t	count;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = dstsize;
	if (size <= dstsize)
		return (srcsize + size);
	count = size - dstsize - 1;
	while (count-- && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dstsize + srcsize);
}
