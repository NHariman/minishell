/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   detail_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:50:43 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/14 19:30:55 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_find_echo_pwd(char **cmd)
{
	int		check[5];
	int		i;

	check[4] = 3;
	check[0] = 0;
	i = 0;
	if (ft_strchr("eE", *cmd[0]))
	{
		check[1] = ft_strchr("cC", cmd[0][1]) ? 0 : 1;
		check[2] = ft_strchr("hH", cmd[0][2]) ? 0 : 1;
		check[3] = ft_strchr("oO", cmd[0][3]) ? 0 : 1;
	}
	else if (ft_strchr("pP", *cmd[0]))
	{
		check[1] = ft_strchr("wW", cmd[0][1]) ? 0 : 1;
		check[2] = ft_strchr("dD", cmd[0][2]) ? 0 : 1;
		check[3] = 0;
	}
	while (i != 4)
	{
		if (check[i] != 0)
			return ;
		i++;
	}
	ft_wordlow(cmd);
}
