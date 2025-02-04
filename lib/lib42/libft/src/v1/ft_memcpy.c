/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:09:54 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:09:57 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy a block of memory from one location to another.
// Dereferencing a NULL pointer to cause a segmentation fault
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (const unsigned char *) src;
	while (n)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		n--;
	}
	return (dest);
}
