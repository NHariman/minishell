/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_enviorment.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 18:42:42 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/11 14:02:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void   ft_split_begin(t_struct_tr *trim)
{
	int		i;

	i = 0;
	if (trim->begin == 0)
		trim->s_begin = ft_strdup("");
	else
	{
		trim->s_begin = (char *)malloc((trim->begin + 1) * sizeof(char));
		while (i < trim->begin)
		{
			trim->s_begin[i] = trim->s_str[i];
			i++;
		}
		trim->s_begin[i] = '\0';		
	}	
}

static void   ft_split_end(t_struct_tr *trim)
{
	int		i;
	int		len;

	i = trim->end;
	len = 0;
	while (trim->s_str[trim->end] && trim->s_str[trim->end] != '\n')
	{
        trim->end++;
		len++;
	}
	trim->s_end = (char *)malloc((len + 1) * sizeof(char));
	len = 0;
	while (i <= trim->end)
	{
		trim->s_end[len] = trim->s_str[i];
		i++;
		len++;
	}
	trim->s_end[len] = '\0';
}

void		ft_split_variable(t_struct_tr *trim, t_shell *shell)
{
	printf("begin c == [%c]\n", trim->s_begin[trim->begin]);
	ft_split_begin(trim);
	printf("begin str == [%s]\n", trim->s_begin);
	ft_get_variable(trim, shell);
	ft_split_end(trim);
    trim->s_cache = ft_strjoin(trim->s_begin, trim->s_variable);
    free(trim->s_begin);
    free(trim->s_variable);
    trim->begin = ft_strlen(trim->s_cache);
    trim->s_str = ft_strjoin(trim->s_cache, trim->s_end);
    free(trim->s_cache);
    free(trim->s_end);
}

void    ft_add_variables(t_struct_m *echo, t_shell *shell)
{
	t_struct_tr trim;

	set_value_trim(&trim);
	trim.s_str = ft_strdup(echo->str);
	trim.begin = echo->i;//$
	free(echo->str);
	if (trim.s_str[trim.begin - 1] == ' ' && trim.begin != 0)
		trim.empty = 1;
	ft_split_variable(&trim, shell);
	echo->str = ft_strdup(trim.s_str);
	free(trim.s_str);
}

void    ft_add_variables_double(t_struct_m *echo, t_shell *shell)
{
	t_struct_tr trim;

	set_value_trim(&trim);
	trim.s_str = ft_strdup(echo->str);
	trim.begin = echo->i;//$
	free(echo->str);
	ft_printf("variable begin i == [%i]\n", trim.begin);
	if (trim.s_str[trim.begin - 1] == ' ' && trim.begin != 0)
		trim.empty = 1;
	ft_split_variable(&trim, shell);
	echo->str = ft_strdup(trim.s_str);
	free(trim.s_str);
}
