/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_sig.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 17:14:10 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/29 19:15:45 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*read_line(t_gnl gnl)
{
	char		buf[1000 + 1];
	char		*tmp;

	gnl.bytes_read = 1;
	while (gnl.bytes_read > 0)
	{
		write(1, "  \b\b", 4);
		gnl.bytes_read = read(gnl.fd, buf, 1000);
		if (gnl.bytes_read < 0)
			return (NULL);
		buf[gnl.bytes_read] = '\0';
		if (!gnl.line_read)
			gnl.line_read = ft_strdup(buf);
		else
		{
			tmp = gnl_strjoin(gnl.line_read, buf);
			gnl.line_read = get_line_read(tmp);
			free(tmp);
		}
		if (!gnl.line_read)
			return (NULL);
		if (find_newline(buf) > -1)
			break ;
	}
	return (gnl.line_read);
}

static int	fill_line(t_gnl gnl, char **line)
{
	int		newline;
	size_t	remainder;

	newline = find_newline(gnl.line_read);
	remainder = 0;
	if (newline != -1)
	{
		if (newline != 0)
			*line = ft_substr(gnl.line_read, 0, newline);
		else
			*line = ft_strdup("");
		remainder = 1;
	}
	else
		*line = ft_strdup(gnl.line_read);
	if (!*line)
		return (-1);
	return (get_fill_line_ret(newline, remainder));
}

static char	*fill_leftover(char *str)
{
	int		newline;
	char	*leftover;

	newline = find_newline(str);
	if (newline != -1)
	{
		leftover = ft_substr(str, newline + 1, ft_strlen(str) - newline - 1);
		if (!leftover)
			return (NULL);
	}
	else
		return (NULL);
	return (leftover);
}

int	get_next_line_sig(int fd, char **line)
{
	static char		*leftover;
	t_gnl			gnl;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl.line_read = NULL;
	gnl.fd = fd;
	*line = gnl.line_read;
	if (leftover)
	{
		gnl.line_read = ft_strdup(leftover);
		free(leftover);
		leftover = NULL;
	}
	if (find_newline(gnl.line_read) == -1)
		gnl.line_read = read_line(gnl);
	if (!gnl.line_read)
		return (-1);
	ret = fill_line(gnl, line);
	gnl.newline = find_newline(gnl.line_read);
	if (gnl.newline != -1)
		leftover = fill_leftover(gnl.line_read);
	free(gnl.line_read);
	return (get_gnl_ret(gnl.newline, leftover, ret));
}
