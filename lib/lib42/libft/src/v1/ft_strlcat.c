/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:23 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:11:25 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// appends string src to the end of dst. 
// then NUL-terminate,
// unless dstsize is 0 or the original dst string was longer than dstsize 
// If the src and dst strings overlap, the behavior is undefined.
// returns the total length of the string that would have been created 
//if there was unlimited space, to the buffersize+sourcestring. 
// means that you can call strlcat() once to find out how much space required, 
// then allocate it if you do not have enough, 
// and finally call strlcat() a second time to create the required string.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_strlen;
	size_t	dst_strlen;
	size_t	space_left;

	src_strlen = ft_strlen(src);
	dst_strlen = ft_strlen(dst);
	space_left = dstsize - dst_strlen - 1;
	if (dstsize == 0)
		return (src_strlen);
	else if (dstsize <= dst_strlen)
		return (dstsize + src_strlen);
	else if (space_left > 0)
	{
		if (src_strlen < space_left)
			space_left = src_strlen;
		ft_memcpy(dst + dst_strlen, src, space_left);
		dst[dst_strlen + space_left] = '\0';
	}
	return (src_strlen + dst_strlen);
}

/*
int main() {
    char dst[20] = "Hello";
    char src[] = " world";

    size_t size = 011 ;
	checker(dst, src, size);
	dst[20] = "Hello";
    src[] = " world";

    size = 20;
	checker(dst, src, size);

	    char dst[20] = "Hello";
    char src[] = " world";

    size_t size = 20;
	checker(dst, src, size);

	    char dst[20] = "Hello";
    char src[] = " world";

    size_t size = 20;
	checker(dst, src, size);

    return 0;
}

void checker(char * dst, const char *src, size_t size)
{

    printf("Using ft_strlcat:\n");
    size_t len1 = ft_strlcat(dst1, src, size);
    printf("Result: %s, Length: %zu\n", dst1, len1);

    printf("Using strlcat:\n");
    size_t len2 = strlcat(dst2, src, size);
    printf("Result: %s, Length: %zu\n", dst2, len2);
}
*/