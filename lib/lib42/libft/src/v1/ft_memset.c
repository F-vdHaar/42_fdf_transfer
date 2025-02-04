/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:10:25 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:10:27 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// writes len bytes of value c (converted to an unsigned char) to the string b
//returns its first argument
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	unsigned char	*ptr;

	val = (unsigned char)c;
	ptr = b;
	while (len)
	{
		*ptr = val;
		ptr++;
		len--;
	}
	return (b);
}
