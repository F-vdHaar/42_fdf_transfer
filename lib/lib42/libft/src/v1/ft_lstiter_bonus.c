/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:13:06 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:13:08 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// iterates over the whole list
//applies the function f to the content fo the elements
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}
