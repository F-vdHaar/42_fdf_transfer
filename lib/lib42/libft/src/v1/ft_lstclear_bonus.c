/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:12:54 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:12:56 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// deletes the passed elemet and all the following elements
// just loop delone
// needs temporary next element because unlike iter we delete stuff
// current = *lst;  dereference lst to get the head of the list: current = *lst;
//Finally, the pointer to the list must be set to NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_elem;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_elem = current->next;
		ft_lstdelone(current, del);
		current = next_elem;
	}
	*lst = NULL;
}
