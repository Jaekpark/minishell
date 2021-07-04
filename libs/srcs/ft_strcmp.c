/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:47:35 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 03:01:05 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (s1)
	{
		if (s1 == s2)
		{
			s1++;
			s2++;
		}
		else
			break ;
	}
	return (*s1 - *s2);
}
