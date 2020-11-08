/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   niks.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:24:35 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/08 16:51:26 by nhariman      ########   odam.nl         */
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

/*
**	int			echo;	- echo command was used
**	int			env;	- env command was used
**	int			exec;	- exec command was used
**	int			envvar;	- an environment variable was called (badly)
**	int			exp;	- export command was used
**	int			err;	- a command that doesn't exist was used
**	int			cd;		- cd was used
**	int			pipe;	- a pipe was used
**	int			pwd;	- pwd was used
**	int			redir;	- a << < or > was used
**	int			semicol; - a semicolon was used
**	int			endstr; - the end of the string has been reached.
*/
typedef struct	s_check
{
	int			echo;
	int			env;
	int			exec;
	int			envvar;
	int			exp;
	int			err;
	int			cd;
	int			pipe;
	int			pwd;
	int			redir;
	int			semicol;
	int			endstr;
}				t_check;

typedef struct	s_shell
{
	t_check		*check;
	char		*echo;
	char		*pwd;
	char		**env;
	char		*pipe;
	char		**exprt;

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
void			ft_qt_start(char *line, t_qts *qts);
void			ft_wordlow(char *line, int start);
void			minishell_parser(char *line, char **envp);

#endif
