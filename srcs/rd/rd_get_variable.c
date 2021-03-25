/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_get_variable.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 18:42:42 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 13:27:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void	ft_save_f(t_struct_tr *trim)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	trim->end = trim->begin;
	while (trim->s_str[trim->end] && trim->s_str[trim->end] != ' '
		&& trim->s_str[trim->end] != '\n' && trim->s_str[trim->end] != '\"'
		&& trim->s_str[trim->end] != '\'')
	{
		trim->end++;
		i++;
	}
	trim->e_check = (char *)malloc((i) * sizeof(char));
	while (len < i)
	{
		trim->e_check[len] = trim->s_str[trim->begin];
		len++;
		trim->begin++;
	}
	trim->e_check[len] = '\0';
}

static int	ft_isleng(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
	{
		i++;
	}
	return (i);
}

static void	ft_cut_env(t_struct_tr *trim, char *str, int i)
{
	int		start;
	int		len;

	len = 0;
	i++;
	start = i;
	while (str[start])
	{
		start++;
		len++;
	}
	trim->s_variable = (char *)malloc((len + 1) * sizeof(char));
	start = i;
	len = 0;
	while (str[start])
	{
		trim->s_variable[len] = str[start];
		start++;
		len++;
	}
	trim->s_variable[len] = '\0';
}

static void	ft_check_variable(t_struct_tr *trim)
{
	int	check;
	int	i;
	int	vari;

	check = ft_strlen(trim->e_check);
	i = 0;
	while (g_shell.env[i] != NULL)
	{
		vari = ft_isleng(g_shell.env[i], '=');
		if (check == vari
			&& ft_strncmp(trim->e_check, g_shell.env[i], check) == 0)
		{
			ft_cut_env(trim, g_shell.env[i], vari);
			if (trim->flag == 3)
			{
				ft_printf("\nbash: %s: Is a directory\n", trim->s_variable);
				trim->flag = 4;
			}
			return ;
		}
		i++;
	}
	trim->error = 1;
	trim->s_variable = ft_strdup("");
}

void	ft_get_variable(t_struct_tr *trim)
{
	trim->begin++;
	ft_save_f(trim);
	ft_check_variable(trim);
	if (trim->s_str[trim->end] == ' ' && trim->empty == 1 && trim->error == 1)
		trim->end++;
	trim->error = 0;
}
