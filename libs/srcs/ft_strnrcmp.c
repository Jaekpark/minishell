/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:19:22 by jaekpark          #+#    #+#             */
/*   Updated: 2021/05/10 02:59:01 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnrcmp(char *s1, char *s2, int cnt)
{
	int i;
	int j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2 || cnt <= 0 || i + 1 < cnt || j + 1 < cnt)
		return (-1);
	while (cnt && i >= 0 && j >= 0)
	{
		if (!s1[i] || !s2[j])
			break ;
		if (s1[i] == s2[j])
		{
			i--;
			j--;
		}
		else if (s1[i] != s2[j])
			return (-1);
		cnt--;
	}
	if (cnt == 0)
		return (0);
	return (-1);
}
