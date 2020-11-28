/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_yusha.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/28 15:55:40 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_yusha.h"

char	*gn_substr(char const *s, int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (gn_strlen(s) < start)
		return (gn_strdup(""));
	size = gn_strlen(s + start);
	if (size < len)
		len = size;
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

int		gn_strlen(const char *s)
{
	int length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}

char	*gn_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*str;

	len = gn_strlen(s1);
	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gn_strjoin(char *s1, char *s2)
{
	char		*strduo;
	int			i;
	int			j;

	i = 0;
	j = 0;
	strduo = (char *)malloc((gn_strlen(s1) + gn_strlen(s2) + 1) * sizeof(char));
	if (!strduo)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && i < gn_strlen(s1))
	{
		strduo[i] = s1[i];
		i++;
	}
	while (s2 && j < gn_strlen(s2))
	{
		strduo[i + j] = s2[j];
		j++;
	}
	strduo[i + j] = '\0';
	free(s1);
	return (strduo);
}
