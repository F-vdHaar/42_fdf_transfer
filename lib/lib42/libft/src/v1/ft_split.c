/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-der <fvon-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:10:53 by fvon-der          #+#    #+#             */
/*   Updated: 2024/10/23 19:03:15 by fvon-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_memory(char **arr);
static int	ft_word_counter(const char *s, char c);
static char	*ft_get_word(const char *str, char c, int *str_ind);

/*
** Function name: ft_split
** Prototype:     char **ft_split(char const *s, char c);
**
** Parameters:
** - s: The string to be split.
** - c: The delimiter character.
**
** Return value:
** - The array of new strings resulting from the split.
** - NULL if the allocation fails.
**
** External functions:
** - malloc
** - free
**
** Description:
** Allocates (with malloc(3)) and returns an array of strings obtained by
** splitting ’s’ using the character ’c’ as a delimiter. The array must end
** with a NULL pointer.
*/
char	**ft_split(char const *str, char c)
{
	char	**result;
	int		i;
	int		pos;
	int		word_count;

	i = -1;
	pos = 0;
	word_count = 0;
	if (str == NULL)
		return (NULL);
	word_count = ft_word_counter(str, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	result[word_count] = NULL ;
	while (++i < word_count)
	{
		result[i] = ft_get_word(str, c, &pos);
		if (result[i] == NULL)
		{
			ft_free_memory(result);
			return (NULL);
		}
	}
	return (result);
}

static void	ft_free_memory(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
	}
	free(arr);
}

static int	ft_word_counter(const char *s, char c)
{
	int	word;
	int	in_word;

	word = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				in_word = 1;
				word++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (word);
}

static char	*ft_get_word(const char *str, char c, int *str_ind)
{
	char	*word;
	int		start_ind;
	int		len;

	len = 0;
	while (str[*str_ind] == c && str[*str_ind])
		(*str_ind)++;
	start_ind = *str_ind;
	while (str[*str_ind] != c && str[*str_ind])
	{
		len++;
		(*str_ind)++;
	}
	if (len > 0)
	{
		word = (char *)malloc(sizeof(char) * (len + 1));
		if (word == NULL)
			return (NULL);
		ft_strlcpy(word, str + start_ind, len + 1);
		return (word);
	}
	return (NULL);
}
/* // Helper function to print the result of ft_split
void print_split(char **result)
{
    if (!result)
    {
        
        return;
    }

    for (int i = 0; result[i]; i++)
    {
        
    }
}

int main(void)
{
    char **result;

    // Test case 1: Regular split
    result = ft_split("      split       this for   me  !       ", ' ');
    
    print_split(result);
    free(result);

    // Test case 2: Split with multiple delimiters
    result = ft_split("Hello,,world,,split,test", ',');
    
    print_split(result);
    free(result);

    // Test case 3: No delimiter in the string
    result = ft_split("NoDelimiterHere", ' ');
    
    print_split(result);
    free(result);

    // Test case 4: String with only delimiters
    result = ft_split(",,,,", ',');
    
    print_split(result);
    free(result);

    // Test case 5: Empty string
    result = ft_split("", ',');
    
    print_split(result);
    free(result);

    // Test case 6: NULL string
    result = ft_split(NULL, ',');
    
    print_split(result);
    free(result);

    return 0;
}
   */