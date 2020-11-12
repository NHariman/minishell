/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/12 12:28:18 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

int		skip_character(char *str, int i, char c)
{
	while (str[i] == c && (str[i]))
	{
		i++;
	}
	return (i);
}

static void		ft_handle_quote(t_struct_m *echo)
{
	//can be smaller
	t_struct_q han;

	set_value_han(&han);
	han.s_str = ft_strdup(echo->str);
	han.i = echo->i;
	free(echo->str);
	if (han.s_str[han.i] == '\'')
	{
		echo_single_str(&han);
	}
	echo->str = ft_strdup(han.s_store);
	free(han.s_str);
	free(han.s_store);
	echo->i = han.i;
}

void		ft_trim_single_c(t_struct_m *echo)
{
	int		i;
	char	*cache;
	int		len;

	i = 0;
	len = 0;
	while (echo->str[len] != '\0' && echo->str[len] != '\n')
		len++;
	cache = (char *)malloc((len - 1) * sizeof(char));
	if (echo->i == 0)
		i++;
	len = 0;
	while (echo->str[i] != '\0' && echo->str[i] != '\n')
	{
		if (i != echo->i)
		{	
			cache[len] = echo->str[i];
			len++;
		}
		i++;
	}
	cache[len] = '\0';
	free(echo->str);
	echo->str = ft_strdup(cache);
	free(cache);
}

void		ft_handle_echo(t_struct_m *echo, t_shell *shell)
{
	while (echo->str[echo->i] && echo->str[echo->i] != '\n')
	{
		if (echo->str[echo->i] == '\\' && (echo->str[echo->i + 1] == '\'' || echo->str[echo->i + 1] == '\"' || echo->str[echo->i + 1] == '$'))
		{
			ft_trim_single_c(echo);//remove the backslash
			echo->i++;//after the symboleafter
		}
		else if (echo->str[echo->i] == '\\' && echo->str[echo->i + 1] == '\\')//single, meaning there is a backslash, so error check
		{
			ft_trim_single_c(echo);//remove the backslash
		}
		else if (echo->str[echo->i] == '$')
		{
			ft_add_variables_double(echo, shell);//checks and takes it
		}
		else if (echo->str[echo->i] == '\"')
		{
			ft_trim_single_c(echo);
		}
		else if (echo->str[echo->i] == '\'')
		{
			ft_handle_quote(echo);
		}
		else
		{
			echo->i++;
		}
	}
}

static void		get_echo_str(t_struct_m *echo)
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	i = 0;
	while (echo->str[len] && echo->str[len])
	{
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	while (echo->str[i] && echo->str[i])
	{
		str[i] = echo->str[echo->i];
		echo->i++;
		i++;
	}
	str[i] = '\0';
	echo->i = 0;
	free(echo->str);
	echo->str = ft_strdup(str);
	free(str);
}

char       *echo_main(char  *str, t_struct_m *echo, t_shell *shell)
{
	set_value_echo(echo);
	echo->str = ft_strdup(str);
	free(str);
	if (echo->str[0] == '\n')
		return (echo->str);
	echo->i = check_flag_n(echo);
	get_echo_str(echo);
	ft_handle_echo(echo, shell);
	if (echo->n == 0)
	{
		echo->cache = ft_strjoin(echo->str, "\n");
		free(echo->str);
		echo->str = ft_strdup(echo->cache);
	}
	printf("end   == [%s]\n", echo->str);
	return (echo->str);
}
