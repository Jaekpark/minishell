/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:45:14 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/07 18:55:49 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*ptr1_tmp;
	unsigned char	*ptr2_tmp;

	ptr1_tmp = (unsigned char *)ptr1;
	ptr2_tmp = (unsigned char *)ptr2;
	while (num--)
	{
		if (*ptr1_tmp != *ptr2_tmp)
			return (*ptr1_tmp - *ptr2_tmp);
		ptr1_tmp++;
		ptr2_tmp++;
	}
	return (0);
}
