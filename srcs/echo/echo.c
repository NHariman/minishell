/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/05 15:59:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("ERROR START\n");
// ft_printf("ERROR END\n");

#include "../minishell.h"
#include <stdio.h>

int	ft_strncmp_echo(int i, char *s1, char *s2, int n)
{
	int y;

	y = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (s1[i] != s2[y])
			return (i - y);//if wrong, then return the original i
		i++;
		y++;
		n--;
	}
	return (i);
}

int		check_flag_n(char *str)
{
	int i;

	i = 0;
	i = skip_character(str, i, ' ');
	if (str[i] == '-')
	{
		while (str[i] == '-')
		{
			i = ft_strncmp_echo(i, str, "-n", 2);
			if (str[i] != ' '  && str[i] != '\n')
			{
				return (i - 2);
			}
			while (str[i] == ' ')
				i++;
		}
		return (i);
	}
	return (i);
}

void        set_value(t_struct_m *echo)
{
	echo->cache 	= ft_strdup("");
	// echo->tmp		= NULL;
	echo->str		= NULL;
	echo->i       	= 0;
	echo->path    	= 0;
	echo->single  	= 0;
	echo->doubble 	= 0;
	echo->beg		= -1;
	echo->end     	= 0;
	echo->len     	= 0;
	echo->stat    	= 0;
	echo->n			= -1;
	echo->error		= 0;
}

int		skip_character(char *str, int i, char c)
{
	while (str[i] == c && str[i])
	{
		i++;
	}
	return (i);
}

void		check_empty_beg(t_struct_m *echo)
{
	int i;

	i = echo->i;
	if (echo->beg == -1)
		echo->beg = 0;
	i--;
	if (echo->str[i] == ' ')
		echo->beg = 1;
	else
		echo->beg = 0;
}

char*	ft_fillstr(char *str1, char	c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str1[i] = c;
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

void	echo_no_str(t_struct_m *echo)
{
	int		z = 0;
	int		y   =	echo->i;
	int     len =   0;
	char*   tmp = 	NULL;

	while (echo->str[echo->i] != '\0' && echo->str[echo->i] != '\n' &&
		echo->str[echo->i] != ' ' && echo->str[echo->i] != '\"' && echo->str[echo->i] != '\'')
		echo->i++;
	len = echo->i - y;
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		echo->error = -1;
	else
	{
		tmp = ft_fillstr(tmp, '0', len);
		while (len >= 0)
		{
			tmp[z] = echo->str[y];
			z++;
			y++;
			len--;
		}
		echo->cache = ft_strjoin(echo->cache, tmp);
		if (echo->beg == 1)
		{
			echo->cache = ft_strjoin(" ", echo->cache);
			echo->beg = 0;
		}
		if (echo->str[echo->i + 1] == ' ')
			echo->cache = ft_strjoin(echo->cache, " ");
		free(tmp);
	}
}

char       *echo_main(char  *str)
{
	t_struct_m *echo;

	echo = ft_calloc(1, sizeof(t_struct_m));
	if (echo == NULL)
		return (NULL);
	set_value(echo);
	echo->str = ft_strdup(str);
	if (echo->str[0] == '\n')
		return (echo->str);
	echo->i = check_flag_n(str);/*now it knows when -n has ended */
	echo->i = skip_character(echo->str, echo->i, ' ');
	while (echo->str[echo->i] != '\n' && echo->str[echo->i] != '\0')
	{
		check_empty_beg(echo);//at the start it will be
		echo->i = skip_character(echo->str, echo->i, ' ');
		if (echo->str[echo->i] != '\"' || echo->str[echo->i] != '\'')
			echo_no_str(echo);
		// else if (echo->str[echo->i] == '\'')
		// 	echo_str_single(echo);
		// else if (echo->str[echo->i] != '\"')
		// 	echo_str_double(echo);
		if (echo->error == -1)
			return (ft_strdup(""));
		//get in, if double or if single isn't a pair, then return a empty cache,
		//and put error on and return the cache immidiently
	}
	if (echo->n != -1)
		echo->cache = ft_strjoin(echo->cache, "\n");
	printf("cache end = %s\n", echo->cache);
	return (echo->cache);
}
