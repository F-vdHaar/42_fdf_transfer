/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:09:34 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:09:36 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// converting a number to a string.
// using negative flag when  divide by  10, so it does not integer overflow

static size_t	get_digit_count(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	int		neg_flag;
	char	*result;

	digits = get_digit_count(n);
	neg_flag = 1;
	result = malloc((digits + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[digits] = '\0';
	if (n < 0)
	{
		neg_flag = -1;
		result[0] = '-';
	}
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		digits--;
		result[digits] = (n % 10 * neg_flag) + '0';
		n = n / 10;
	}
	return (result);
}
