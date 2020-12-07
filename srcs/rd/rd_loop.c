/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/12/07 10:52:55 by anonymous     ########   odam.nl         */
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
			rd->nb = 2;
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
	else if (rd->fd_rd != -1)
		close(rd->fd_rd);
	if (rd->nb == 1)
	   rd->fd = open(rd->file, O_RDWR | O_TRUNC | O_CREAT, 0666);
	else if (rd->nb == 2)
		rd->fd = open(rd->file, O_RDWR | O_APPEND | O_CREAT, 0666);
	else if (rd->nb == 3)
		rd->fd_rd = open(rd->file, O_RDWR);
	if (rd->fd < 0 || rd->fd_r < 0)
	{
		ft_printf_err("Error\n%s\n", strerror(errno));
		shell->exit_code = 1;
	}
}

void    rd_open_file_fill(t_struct_rd *rd, t_shell *shell)
{
	if (rd->fd != -1)
	{
		shell->fd = rd->fd;
		close(rd->fd);
	}
	else if (rd->fd_rd != -1)
	{
		shell->fd_rd = rd->fd_rd
		close(rd->fd_rd);
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
		ft_printf("file == [%s]\n", rd->file);
		rd_open_file(rd);
	}
	rd_open_file_fill(rd, shell);
	free(echo);
	return (rd->error);
}
