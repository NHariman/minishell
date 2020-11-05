/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   niks.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:24:35 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/05 13:10:27 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIKS_H
# define NIKS_H

typedef struct	s_gnl
{
	int				bytes_read;
	int				fd;
	char			*line_read;
}				t_gnl;

/*
** dq: checks for equal amount of double quotes " "
** sq: checks for equal amount of single quotes ' '
*/

typedef struct	s_echo
{
	int			dq;
	int			sq;
}				t_echo;
int				get_next_line(int fd, char **line);
int				ft_echo_parser(char *line);

#endif
