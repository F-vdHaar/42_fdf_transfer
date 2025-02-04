/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:58 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:12:00 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locates the LAST locates occurrence of c (converted to a char)
//in string pointed to by s.
char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char) c)
			last_occurrence = ((char *)s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (last_occurrence);
}
