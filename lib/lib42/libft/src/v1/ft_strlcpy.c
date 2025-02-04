/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:30 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:11:31 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*copies up to dstsize - 1 characters from the string src to dst,
 NUL-terminating the result if dstsize is not 0.
  return the total length of the string they tried to create. 
  that means the length of src.*/

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < n)
		ft_memcpy(dest, src, src_len + 1);
	else if (n != 0)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = 0;
	}
	return (src_len);
}

/*

int main() {
    char source[] = "Eggs and ham!";
    char destination[5];

    ft_strncpy(destination, source, 0);

    return 0;
}
*/