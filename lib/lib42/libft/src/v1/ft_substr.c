/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:12:11 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/23 16:01:09 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		s_len = 0;
	else if (len >= ft_strlen(s) - start)
		s_len = ft_strlen(s) - start;
	else
		s_len = len;
	str = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (!s || !str)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	while (i < s_len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int main() {
	// Test cases
	char *test_str = "Hello, World!";
	
	// Case 1: Normal case
	char *result1 = ft_substr(test_str, 0, 5); // Expected: "Hello"
	free(result1);
	
	// Case 2: Substring starting from middle
	char *result2 = ft_substr(test_str, 7, 5); // Expected: "World"
	free(result2);
	
	// Case 3: Length greater than string length
	char *result3 = ft_substr(test_str, 0, 20); // Expected: "Hello, World!"
	free(result3);
	
	// Case 4: Start index out of bounds
	char *result4 = ft_substr(test_str, 20, 5); // Expected: ""
	free(result4);
	
	// Case 5: Start index within the string but no length
	char *result5 = ft_substr(test_str, 5, 0); // Expected: ""
	free(result5);

	// Case 6: Null input string
	char *result6 = ft_substr(NULL, 0, 5); // Expected: (null)
		// Case 7: Start index is greater than the string length
	char *result7 = ft_substr(test_str, 15, 5); // Expected: ""
	free(result7);

	return 0;
} */