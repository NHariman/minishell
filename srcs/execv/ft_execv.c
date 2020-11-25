/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_execv.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:27:59 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/25 22:14:14 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



static int		ft_execve(char **argv, t_shell *shell)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;
	
	errno = 0;
	tpid = 0;
	child_pid = fork();
	if (child_pid == 0)
	{
		execve(argv[0], argv, shell->env);
		ft_printf_err("minishell: %s: %s(%i)\n", argv[0],
		strerror(errno), errno);
		exit (0);
	}
	else
	{
		while (tpid != child_pid)
			tpid = wait(&child_status);
	}
	return (0);
}

void			ft_execute(char *cmd, char *str, t_shell *shell)
{
	char	**argv;
	char	**tmp;
	int		i;
	int		check;
	int		len;

	i = 0;
	shell->exit_code = 0;
	len = ft_count_arr(str);
	if (len == 0)
		argv = empty_array(cmd);
	else
	{
		tmp = ft_argv(str, shell);
		argv =  ft_add_arr_front(tmp, cmd);
	}
	errno = 0;
	check = ft_execve(argv, shell);
	ft_free_array(argv, len);
	return ;

}