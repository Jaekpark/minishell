/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:13:14 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/14 16:11:38 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	buffer_size;
	char	*result;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	buffer_size = end - start + 1;
	if (!(result = malloc(sizeof(char) * (buffer_size + 1))))
		return (NULL);
	ft_strlcpy(result, &s1[start], buffer_size + 1);
	return (result);
}
