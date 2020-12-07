/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_yusha.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/28 15:55:13 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_YUSHA_H
# define GET_NEXT_LINE_YUSHA_H

# define BUFFER_SIZE 10000
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_ynl
{
	int			bytes_read;
	int			fd;
	char		*line_read;
	int			newline;
}				t_ynl;

char			*gn_substr(char const *s, int start, size_t len);
int				gn_strlen(const char *s);
char			*gn_strdup(const char *s1);
char			*gn_strjoin(char *s1, char *s2);
int				get_next_line_yusha(int fd, char **line);

#endif
