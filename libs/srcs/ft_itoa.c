/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:43:42 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/15 14:14:40 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			arr_size(int n)
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

char		*ft_itoa(int n)
{
	char	*dst;
	int		dstsize;

	dstsize = n < 0 ? arr_size(n) + 2 : arr_size(n) + 1;
	if (!(dst = malloc(sizeof(char) * dstsize)))
		return (NULL);
	dst[--dstsize] = '\0';
	if (n < 0)
	{
		dst[0] = '-';
		if (n == -2147483648)
		{
			dst[1] = '2';
			n = -147483648;
		}
		n *= -1;
	}
	while (1)
	{
		dst[--dstsize] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return (dst);
}
