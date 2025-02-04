/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:12:34 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:12:36 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_str(const char *set, char c);

char	*ft_strtrim(const char *s1, const char *set)
{
	int		s1_start;
	int		s1_end;
	char	*res;

	s1_start = 0;
	s1_end = ft_strlen(s1);
	res = ft_strdup(s1);
	if (!s1 || !res)
		return (NULL);
	while (res[s1_end])
	{
		if (is_in_str(set, s1[--s1_end]))
			res[s1_end] = '\0';
	}
	while (res)
	{
		if (is_in_str(set, s1[++s1_start]))
			res++;
		else
			break ;
	}
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
