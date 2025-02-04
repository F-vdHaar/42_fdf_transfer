/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:33:16 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/23 13:42:06 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// MAN PAGE
// DESCRIPTION
//      The isalpha() function tests for any character for 
// which isupper(3) or islower(3) is true. 
// 	 The value of the argument must be representable 
// as an unsigned char or the value of EOF.
// RETURN VALUES
//      The isalpha() function returns zero if the character tests false and
// returns non-zero if the character tests true.

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}

int	ft_isupper(int c)
{
	int	res;

	res = 0;
	if (c >= 'A' && c <= 'Z')
		res = 1;
	return (res);
}

int	ft_islower(int c)
{
	int	res;

	res = 0;
	if (c >= 'a' && c <= 'z')
		res = 1;
	return (res);
}

/*
int main() {

	char source[] = "greeneggsandham";

    ft_str_is_alpha(source);

    return 0;
}
*/