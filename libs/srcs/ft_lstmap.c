/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:05:20 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/19 13:35:01 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_data;

	if (!lst || !f)
		return (NULL);
	new_node = NULL;
	while (lst)
	{
		if (!(new_data = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_data, del);
			break ;
		}
		ft_lstadd_back(&new_node, new_data);
		lst = lst->next;
	}
	return (new_node);
}
