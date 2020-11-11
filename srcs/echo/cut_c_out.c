/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/11 17:40:44 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

void		ft_trim_character(t_struct_m *echo, t_struct_q *han)
{
	//is not trimming the backslash
	int		i;
	int		len;

    ft_printf("character trim in == [%c] i == [%i]\n", han->s_str[echo->i], echo->i);
	i = echo->i - 1;
	len = 0;
	if (i == -1)
		echo->cache = ft_strdup("");
	else
	{
		echo->cache = (char *)malloc((i + 1) * sizeof(char));
		while (len <= echo->i)
		{
			echo->cache[len] = han->s_str[len];
			len++;
		}
		echo->cache[i] = '\0';
    }
	i = echo->i + 1;//after character now
    ft_printf("cgaracter == [%c]\n", han->s_str[i]);
    len = 0;
	while(han->s_str[i] && han->s_str[i] != '\n')
	{
		i++;
		len++;
	}
	i = echo->i + 1;
	echo->tmp = (char *)malloc((len + 1) * sizeof(char));
	len = 0;
	while (han->s_str[i])
	{
		echo->tmp[len] = han->s_str[i];
		i++;
		len++;
	}
	echo->tmp[len] = '\0';
    free(han->s_str);
	han->s_str = ft_strjoin(echo->cache, echo->tmp);
    ft_printf("cache == [%s]\n", echo->cache);
	ft_printf("tmp == [%s]\n", echo->tmp);
	free(echo->cache);
	free(echo->tmp);
}