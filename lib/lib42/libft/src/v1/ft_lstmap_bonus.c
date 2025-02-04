/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:13:18 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/23 17:02:33 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* like iter, but creates a new list
/ check if lst or f or del is NULL */
//loop over lst */
/* create a new element */
/* if new elem is null, clear the new list */
/* add the new element to the back of the list */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (new_content == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_obj = ft_lstnew(new_content);
		if (!new_obj)
		{
			ft_lstclear(&new_list, del);
			return (del(new_content), NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
