/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 21:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 19:12:30 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	small_move(unsigned char **dest, unsigned char **source, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		i = i + 1;
		*dest[len - i] = *source[len - i];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if ((!dst && !src))
		return (NULL);
	if (((size_t)(dest - source)) < len)
		small_move(&dest, &source, len);
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
