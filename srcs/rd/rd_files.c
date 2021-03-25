/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_files.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 12:14:19 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 13:27:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static	void	rd_file_free(t_struct_rd *rd, int i, t_struct_m *echo)
{
	rd->cache[i] = '\0';
	rd->tmp = ft_strtrim(rd->cache, "\n");
	free(rd->cache);
	rd->cache = ft_strdup(echo_main(rd->tmp, echo));
	rd->file = ft_strtrim(rd->cache, "\n");
	free(rd->cache);
	free(echo->tmp);
	free(echo->str);
}

void	rd_get_file(t_struct_rd *rd, t_struct_m *echo)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	start = rd->i;
	while (rd->str[rd->i] != '\n' && rd->str[rd->i] != '\0'
		&& rd->str[rd->i] != '<' && rd->str[rd->i] != '>')
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
	rd_file_free(rd, i, echo);
}

void	rd_open_file(t_struct_rd *rd)
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
		g_shell.exit_code = 1;
	}
}
