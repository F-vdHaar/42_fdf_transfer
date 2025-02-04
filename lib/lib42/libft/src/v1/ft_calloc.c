/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:08:03 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:08:08 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// malloc but  all the memory bytes are set to 0
//any arithm operation resulting in value greater than SIZE_MAX will overflow.

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	t_size;
	void	*memptr;

	if (num_elements == 0 || element_size == 0)
		return (malloc(0));
	if (element_size > SIZE_MAX / num_elements
		|| num_elements > SIZE_MAX / element_size)
		return (NULL);
	t_size = num_elements * element_size;
	memptr = malloc(t_size);
	if (memptr != NULL)
	{
		ft_bzero(memptr, t_size);
	}
	return (memptr);
}
