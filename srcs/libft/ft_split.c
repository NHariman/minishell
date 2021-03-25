/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:36:05 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/25 11:09:39 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arraycount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_deletearray(char **array, size_t len)
{
	while (len > 0)
	{
		len--;
		free(array[len]);
	}
	free(array);
	return (NULL);
}

static char	*fill_array(size_t *i, char const *s, char c)
{
	size_t	len;
	char	*str;

	len = 0;
	while (s[*i] != c && s[*i])
	{
		*i = *i + 1;
		len++;
	}
	str = ft_substr(s, *i - len, len);
	if (!str)
		return (NULL);
	return (str);
}

static char	**ft_createarray(char **array, char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[j] = fill_array(&i, s, c);
			if (!array)
				return (ft_deletearray(array, j));
		}
		else
			i++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char		**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_arraycount(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_createarray(split, s, c);
	return (split);
}
