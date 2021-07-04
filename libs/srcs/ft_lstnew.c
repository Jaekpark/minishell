/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:01:10 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/15 15:54:17 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = malloc(sizeof(t_list) * 1)))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
