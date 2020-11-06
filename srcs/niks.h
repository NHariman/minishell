/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   niks.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:24:35 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/06 22:17:56 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIKS_H
# define NIKS_H

# define SQ 1
# define DQ 2

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

typedef struct	s_qts
{
	int			dq;
	int			sq;
}				t_qts;

typedef struct	s_shell
{
	char		*echo;
	char		*pwd;
	char		**env;
	char		*export;

}				t_shell;

int				get_next_line(int fd, char **line);
int				ft_echo_parser(char *line, int *i, t_shell *shell);
void			ft_cd(char *str);
char			*ft_pwd(void);
char			*ft_rm_endline(char *str);
char			*gnl_strjoin(char *s1, char *s2);
char			*ft_find_arg(char *str, int *i);
void			ft_set_qts(t_qts *qts);
void			ft_qt_line(char *line, t_qts *qts, int *i);

#endif
