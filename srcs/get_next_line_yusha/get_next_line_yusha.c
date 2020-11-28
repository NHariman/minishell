/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_yusha.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/28 15:59:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_yusha.h"

static int				find_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char				*read_line(t_ynl gnl)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	gnl.bytes_read = 1;
	while (gnl.bytes_read > 0)
	{
		gnl.bytes_read = read(gnl.fd, buf, BUFFER_SIZE);
		if (gnl.bytes_read < 0)
			return (NULL);
		buf[gnl.bytes_read] = '\0';
		if (!gnl.line_read)
			gnl.line_read = gn_strdup(buf);
		else
		{
			tmp = gn_strjoin(gnl.line_read, buf);
			gnl.line_read = (!tmp ? NULL : gn_strdup(tmp));
			free(tmp);
		}
		if (!gnl.line_read)
			return (NULL);
		if (find_newline(buf) > -1)
			break ;
	}
	return (gnl.line_read);
}

static int				fill_line(t_ynl gnl, char **line)
{
	int		newline;
	size_t	remainder;

	newline = find_newline(gnl.line_read);
	remainder = 0;
	if (newline != -1)
	{
		if (newline != 0)
			*line = gn_substr(gnl.line_read, 0, newline);
		else
			*line = gn_strdup("");
		remainder = 1;
	}
	else
		*line = gn_strdup(gnl.line_read);
	if (!*line)
		return (-1);
	return (newline != -1 && remainder ? 1 : 0);
}

static char				*fill_leftover(char *str)
{
	int		newline;
	char	*leftover;

	newline = find_newline(str);
	if (newline != -1)
	{
		leftover = gn_substr(str, newline + 1, gn_strlen(str) - newline - 1);
		if (!leftover)
			return (NULL);
	}
	else
		return (NULL);
	return (leftover);
}

int						get_next_line_yusha(int fd, char **line)
{
	static char		*leftover;
	t_ynl			gnl;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl.line_read = NULL;
	gnl.fd = fd;
	*line = gnl.line_read;
	if (leftover)
	{
		gnl.line_read = gn_strdup(leftover);
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
	return ((gnl.newline != -1 && !leftover) ? -1 : ret);
}
