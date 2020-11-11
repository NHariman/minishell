/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/12 00:50:18 by anonymous     ########   odam.nl         */
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
	t_struct_q han;

	set_value_han(&han);
	han.s_str = ft_strdup(echo->str);
	han.i = echo->i;
	free(echo->str);
	// if (han.s_str[echo->i] == '\"')
	// {
		
	// 	ft_trim_character(echo, &han);//remove the backslash
	// 	ft_printf("when double check i == [%i]] c == [%c] str == [%s]\n", echo->i, han.s_str[echo->i], han.s_str);
	// 	while (han.s_str[echo->i] != '\"')
	// 	{
	// 		if (han.s_str[echo->i] == '\\' && (han.s_str[echo->i + 1] == '\'' || han.s_str[echo->i + 1] == '\"' || han.s_str[echo->i] == '$'))
	// 		{
	// 			ft_trim_character(echo, &han);//remove the backslash
	// 			echo->i++;//after the symboleafter
	// 		}
	// 		else if (han.s_str[echo->i] == '\\' && han.s_str[echo->i + 1] == '\\')//single, meaning there is a backslash, so error check
	// 		{
	// 			ft_printf("---start---\n");
	// 			ft_trim_character(echo, &han);//removes the backslash
	// 			echo->i++;
	// 		}
	// 		else if (han.s_str[echo->i] == '$')
	// 			ft_add_variables_double(echo, shell);//doesn't store it in the right str, use han
	// 		else
	// 			echo->i++;					
	// 	}
	// 	/*
	// 	take the echo->i and use it to malloc and take everthing from before
	// 	echo->i++; so after the character
	// 	then take strlen from han->s_str - echo->i == len
	// 	save this end
	// 	strjoin
	// 	done
	// 	*/
	// 	ft_trim_character(echo, &han);//remove the backslash
	// 	ft_printf("after double check c == [%c] str == [%s]\n", han.s_str[echo->i], han.s_str);
	// 	// echo->i = han.i;
	// 	// echo_double_str(&han);
	// }
	if (han.s_str[han.i] == '\'')
	{
		echo_single_str(&han);
	}
	echo->str = ft_strdup(han.s_store);
	free(han.s_str);
	free(han.s_store);
	echo->i = han.i;
}

// void		ft_trim_backslash(t_struct_m *echo)
// {
// 	//is not trimming the backslash
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = 0;
// 	echo->i--;//one character back
// 	ft_printf("in backslash i == [%i]\n", echo->i);
// 	if (echo->i < 0)
// 		echo->cache = ft_strdup("");
// 	else
// 	{
// 		echo->cache = (char *)malloc((echo->i + 1) * sizeof(char));
// 		while (i <= echo->i)
// 		{
// 			echo->cache[i] = echo->str[i];
// 			i++;
// 		}
// 		echo->cache[i] = '\0';
// 	}
// 	echo->i += 2;
// 	i = echo->i;
// 	while(echo->str[i] && echo->str[i] != '\n' && echo->str[i])
// 	{
// 		i++;
// 		len++;
// 	}
// 	i = i - len;
// 	echo->tmp = (char *)malloc((len + 1) * sizeof(char));
// 	len = 0;
// 	while (echo->str[i] && echo->str[i] != '\n' && echo->str[i])
// 	{
// 		echo->tmp[len] = echo->str[i];
// 		i++;
// 		len++;
// 	}
// 	echo->tmp[len] = '\0';
// 	echo->str = ft_strjoin(echo->cache, echo->tmp);
// 	ft_printf("tmp == [%s]\n", echo->tmp);
// 	free(echo->cache);
// 	free(echo->tmp);
// }

void		ft_trim_backslash(t_struct_m *echo)
{
	int		i;

	i = 0;
	ft_printf("str == [%s]\n", echo->str);
	ft_printf("c == [%c] i == [%i]\n", echo->str, echo->str[echo->i], echo->i);
	echo->cache = (char *)malloc((ft_strlen(echo->str)) * sizeof(char));
	while (echo->str[i] && echo->str[echo->i] != '\n')
	{
		if (i == echo->i)
			i++;
		else
		{
			echo->cache[i] = echo->str[i];
			i++;	
		}
	}
	echo->cache[i] = '\0';
	free(echo->str);
	echo->str = ft_strdup(echo->cache);
	ft_printf("cache == [%s]\n", echo->cache);
	ft_printf("----END----\n");
	free(echo->cache);
}

void		ft_handle_echo(t_struct_m *echo, t_shell *shell)
{
	ft_printf("start handle input == [%s], i ==[%i] c == [%c]\n", echo->str, echo->i, echo->str[echo->i]);
	while (echo->str[echo->i] && echo->str[echo->i] != '\n')
	{
		if (echo->str[echo->i] == '\\' && (echo->str[echo->i + 1] == '\'' || echo->str[echo->i + 1] == '\"' || echo->str[echo->i + 1] == '$'))
		{
			ft_trim_backslash(echo);//remove the backslash
			echo->i++;//after the symboleafter
		}
		else if (echo->str[echo->i] == '\\' && echo->str[echo->i + 1] == '\\')//single, meaning there is a backslash, so error check
		{
			ft_trim_backslash(echo);//remove the backslash
		}
		else if (echo->str[echo->i] == '$')
		{
			ft_add_variables(echo, shell);//checks and takes it
		}
		else if (echo->str[echo->i] == '\"')
		{
			ft_trim_backslash(echo);//remove the backslash
			//check the characters here			
		}
		else if (echo->str[echo->i] == '\'')
			ft_handle_quote(echo);
		else
		{
			echo->i++;
		}
	}
}
char       *echo_main(char  *str, t_struct_m *echo, t_shell *shell)
{
	set_value_echo(echo);
	echo->str = ft_strdup(str);
	free(str);
	if (echo->str[0] == '\n')
		return (echo->str);
	echo->i = check_flag_n(echo);
	printf("-n == [%i]\n", echo->n);
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
