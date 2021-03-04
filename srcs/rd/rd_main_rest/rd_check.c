/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/12/01 13:17:33 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

// int			ft_check_rd_echo(t_struct_rd *rd, t_shell *shell)
// {
// 	int		len;
// 	int		i;

// 	len = 0;
// 	rd->txt = 0;
// 	free(rd->string);
// 	while (shell->echo[len] != '\n' && shell->echo[len])
// 		len++;
// 	rd->string = (char *)malloc((len + 1) * sizeof(char));
// 	i = 0;
// 	while (len > 0)
// 	{
// 		rd->string[i] = shell->echo[i];
// 		i++;
// 		len--;
// 	}
// 	rd->string[i] = '\0';
// 	return (0);
// }

// int			ft_check_rd(t_struct_rd *rd, t_shell *shell)
// {
// 	rd->txt = 0;
// 	if (shell->check.echo == 1)
// 		ft_check_rd_echo(rd, shell);
// 	if (shell->check.pwd == 1)
// 	{
// 		rd->txt = 1;//ignore strings
// 		ft_check_rd_echo(rd, shell);
// 	}
// 	if (shell->check.env == 1)
// 	{
// 		rd->txt = 2;//no strings allowed
// 		ft_check_rd_echo(rd, shell);
// 	}
// 	if (shell->check.exp == 1)
// 	{
// 		rd->txt = 3;//no strings allowed
// 		ft_check_rd_echo(rd, shell);
// 	}
// 	else
// 		return (1);
// 	return (0);
// }