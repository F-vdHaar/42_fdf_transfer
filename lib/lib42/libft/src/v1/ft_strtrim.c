/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:12:04 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/14 16:17:50 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_str(const char *set, char c);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	s1_start;
	size_t	s1_end;
	char	*res;

	s1_start = 0;
	if (!s1)
		return (NULL);
	s1_end = ft_strlen(s1);
	while (s1_start < s1_end && is_in_str(set, s1[s1_start]))
		s1_start++;
	while (s1_end > s1_start && is_in_str(set, s1[s1_end - 1]))
		s1_end--;
	res = ft_substr(s1, s1_start, s1_end - s1_start);
	return (res);
}

char	*ft_trim(const char *s1, const char *set)
{
	size_t	s1_start;
	size_t	s1_end;
	char	*res;

	s1_start = 0;
	if (!s1)
		return (NULL);
	s1_end = ft_strlen(s1);
	while (s1_start < s1_end && is_in_str(set, s1[s1_start]))
		s1_start++;
	while (s1_end > s1_start && is_in_str(set, s1[s1_end - 1]))
		s1_end--;
	res = ft_substr(s1, s1_start, s1_end - s1_start);
	return (res);
}

static int	is_in_str(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
