/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:43:42 by jaekpark          #+#    #+#             */
/*   Updated: 2021/02/25 01:22:36 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_size(unsigned int n)
{
	int		count;

	count = 1;
	while (1)
	{
		if (n / 10 == 0)
			break ;
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_uitoa(unsigned int n)
{
	char	*dst;
	int		dstsize;

	dstsize = arr_size(n) + 1;
	if (!(dst = malloc(sizeof(char) * dstsize)))
		return (NULL);
	dst[--dstsize] = '\0';
	while (1)
	{
		dst[--dstsize] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return (dst);
}
