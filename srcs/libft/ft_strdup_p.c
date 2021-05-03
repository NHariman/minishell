/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 04:44:56 by nhariman      #+#    #+#                 */
/*   Updated: 2021/05/03 14:06:54 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_p(const char *s)
{
	size_t	length;

	if (!s)
		return (-1);
	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup_p(const char *s1)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen_p(s1);
	if (len < 0)
		return (NULL);
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
