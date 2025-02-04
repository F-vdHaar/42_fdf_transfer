/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:13:12 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:13:14 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_lst;

	temp_lst = lst;
	if (!lst)
		return (NULL);
	while (temp_lst->next)
		temp_lst = temp_lst->next;
	return (temp_lst);
}
