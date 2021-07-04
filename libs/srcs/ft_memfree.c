/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:53:01 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/03 15:41:20 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_free_single(void *ptr)
{
	if (!ptr)
		return (-1);
	free(ptr);
	ptr = NULL;
	return (1);
}

int		ft_free_double(void **ptr)
{
	int i;

	if (!ptr)
		return (-1);
	i = -1;
	while (ptr[++i] != NULL)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
	return (1);
}
