/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_variable.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 22:22:54 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/08 22:22:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void   ft_split_begin(t_struct_tr *trim)
{
	int		i;

	i = 0;
	trim->s_begin = (char *)malloc((trim->begin + 1) * sizeof(char));
	while (i < trim->begin)
	{
		trim->s_begin[i] = trim->s_str[i];
		i++;
	}
	trim->s_begin[i] = '\0';
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
	ft_split_begin(trim);
	ft_get_variable(trim, shell);
	ft_split_end(trim);
    ft_printf("begin == [%s]\n", trim->s_begin);
    ft_printf("variable == [%s]\n", trim->s_variable);
	ft_printf("end == [%s]\n", trim->s_end);
    trim->s_cache = ft_strjoin(trim->s_begin, trim->s_variable);
    free(trim->s_begin);
    free(trim->s_variable);
    trim->begin = ft_strlen(trim->s_cache);
    trim->s_str = ft_strjoin(trim->s_cache, trim->s_end);
    free(trim->s_cache);
    free(trim->s_end);
}
