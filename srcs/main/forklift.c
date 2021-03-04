/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forklift.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 15:18:42 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/04 15:18:56 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_forklift(char *line, t_shell *shell)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;

	tpid = 0;
	child_pid = fork();
	if (child_pid == 0)
	{
		minishell_parser(line, shell);
		exit (
	}
}
