/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:10:48 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/08 20:10:50 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//write a string on a specified file descriptor

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str);
	if (!str || fd < 0)
		return ;
	write(fd, str, len);
}
