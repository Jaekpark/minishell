/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 00:25:58 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/07 01:10:15 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t num)
{
	size_t	i;
	char	*dst_tmp;

	i = 0;
	dst_tmp = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (num > 0)
		{
			dst_tmp[num - 1] = ((char *)src)[num - 1];
			num--;
		}
	}
	else
	{
		while (i < num)
		{
			dst_tmp[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
