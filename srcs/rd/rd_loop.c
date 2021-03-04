/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/04 15:00:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int    rd_get_nb(t_struct_rd *rd)
{
	while (rd->str[rd->i] == ' ')
		rd->i++;
	if (rd->str[rd->i] != '<' && rd->str[rd->i] != '>')
		return (1);
	else if (rd->str[rd->i] == '<')
	{
		rd->nb = 3;
		while (rd->str[rd->i] == '<' || rd->str[rd->i] == ' ')
			rd->i++;
		return (rd->error);
	}
	else
	{
		if (rd->str[rd->i] == '>')
			rd->nb = 1;
		rd->i++;
		if (rd->str[rd->i] == '>')
		{
			rd->nb = 2;
			rd->i++;
		}
		while (rd->str[rd->i] == ' ')
			rd->i++;
	}
	return (0);
}

void rd_get_file(t_struct_rd *rd, t_shell *shell, t_struct_m *echo)
{
	int     i;
	int     len;
	int     start;

	i = 0;
	start = rd->i;
	while (rd->str[rd->i] != '\n' && rd->str[rd->i] != '\0' &&
	rd->str[rd->i] != '<' && rd->str[rd->i] != '>')
		rd->i++;
	len = rd->i - start;
	rd->i = start;
	rd->cache = (char *)malloc(len * sizeof(char));
	while (len > 0)
	{
		rd->cache[i] = rd->str[rd->i];
		i++;
		rd->i++;
		len--;
	}
	rd->cache[i] = '\0';
	rd->tmp = ft_strtrim(rd->cache, "\n");
	free(rd->cache);
	rd->cache = ft_strdup(echo_main(rd->tmp, echo, shell));
	// free(rd->tmp);
	rd->file = ft_strtrim(rd->cache, "\n");
	free(rd->cache);
	free(echo->tmp);
	free(echo->str);
}

void    rd_open_file(t_struct_rd *rd, t_shell *shell)
{
	errno = 0;
	if (rd->fd != -1)
		close(rd->fd);
	else if (rd->fd_rd != -1 && rd->nb == 3)
		close(rd->fd_rd);
	if (rd->nb == 1)
	   rd->fd = open(rd->file, O_RDWR | O_TRUNC | O_CREAT, 0666);
	else if (rd->nb == 2)
		rd->fd = open(rd->file, O_RDWR | O_APPEND | O_CREAT, 0666);
	else if (rd->nb == 3)
		rd->fd_rd = open(rd->file, O_RDWR);
	printf("--error check--\n");
	if (rd->fd < 0 && rd->fd_rd < 0)
	{
		ft_printf_err("Error\n%s\n", strerror(errno));
		shell->exit_code = 1;
	}
}

void	rd_one(t_struct_rd *rd, t_shell *shell)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;

	tpid = 0;
	shell->fd = rd->fd;
	child_pid = fork();
	if (child_pid == 0)
	{
		dup2(rd->fd, 1);
		ft_wordparser(shell);
		close(1);
		close(rd->fd);
		exit(0);
		//is er een error
		//stdin 1 eruit lezen
		
		//leeg maken
		//weet neit of het leeg meot
		//we now have just cose it after wordparser
		//put that in de file
	}
	else
	{
		while (tpid != child_pid)
		{
			tpid = wait(&child_status);
		}
		ft_printf("exit\n");
	}
}

void	rd_two(t_struct_rd *rd, t_shell *shell)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;

	tpid = 0;
	shell->fd_r = rd->fd_rd;
	child_pid = fork();
	if (child_pid == 0)
	{
		printf("---<---\n");
		dup2(rd->fd_rd, 0);
		ft_wordparser(shell);
		//stdin 0 in stoppen
		//put that in de file
		//is er een error
		close(0);
		close(rd->fd_rd);
		exit(0);
	}
	else
	{
		while (tpid != child_pid)
		{
			tpid = wait(&child_status);
		}
	}
}

void    rd_open_file_fill(t_struct_rd *rd, t_shell *shell)
{
	if (rd->fd != -1)
	{
		rd_one(rd, shell);
	}
	else if (rd->fd_rd != -1)
	{
		rd_two(rd, shell);
	}
}

int     rd_loop(t_struct_rd *rd, t_shell *shell)
{
	t_struct_m	*echo;

	echo = ft_calloc(1, sizeof(t_struct_m));
	rd->i = 0;
	rd->error = 0;
	while (rd->str[rd->i] && rd->str[rd->i] != '\n' && rd->error == 0)
	{
		rd_value_rd(rd);
		rd->error = rd_get_nb(rd);
		if (rd->error > 0)
		{
			free(echo);
			return (rd->error);
		}
		rd_get_file(rd, shell, echo);
		// ft_printf("file == [%s]\n", rd->file);
		rd_open_file(rd, shell);
	}
	rd_open_file_fill(rd, shell);
	free(echo);
	return (rd->error);
}
