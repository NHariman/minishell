/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_file.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 17:14:10 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/15 19:36:48 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*read_line(t_gnl gnl)
{
	char		buf[1000 + 1];
	char		*tmp;

	gnl.bytes_read = 1;
	while (gnl.bytes_read > 0)
	{
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
	}
	return (gnl.line_read);
}

static int	fill_line(t_gnl gnl, char **line)
{
	*line = ft_strdup(gnl.line_read);
	if (!*line)
		return (-1);
	return (0);
}

int	get_file_contents(int fd, char **line)
{
	t_gnl			gnl;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl.line_read = NULL;
	gnl.fd = fd;
	*line = gnl.line_read;
	gnl.line_read = read_line(gnl);
	if (!gnl.line_read)
		return (-1);
	ret = fill_line(gnl, line);
	free(gnl.line_read);
	return (ret);
}
