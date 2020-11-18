/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   niks.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:24:35 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/18 20:31:37 by nhariman      ########   odam.nl         */
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

typedef	struct	s_trim
{
	int			start;
	char		*res;
}				t_trim;

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
**	int			exp;	- export command was used
**	int			pwd;	- pwd was used
*/
typedef struct	s_check
{
	int			echo;
	int			env;
	int			exp;
	int			err;
	int			pwd;
}				t_check;

typedef struct	s_shell
{
	t_check		check;
	int			exit_code;
	char		*echo;
	char		*pwd;
	char		**env;
	char		*env_s;
	char		*err;
	char		**exprt;

}				t_shell;

/*
** general functions
*/

char			*ft_rm_endline(char *str);
int				exit_minishell(void);
char			*gnl_strjoin(char *s1, char *s2);
char			*ft_find_arg(char *cmd, char *str, int *i);
int				get_next_line(int fd, char **line);
char			*ft_find_variable(char *str, int *i, t_shell *shell);
char			*ft_find_envvar(char *var, t_shell *shell);
char			*ft_charjoin(char *str, char c);
char			*ft_make_single_char_str(char c);
void			ft_strspecial(char *str, t_trim *trim, int *i, char c);
void			ft_parse_dollar(char *str, int *i,
							t_trim *trim, t_shell *shell);
char			*ft_doublequotes_str(char *str, int *i, t_shell *shell);
char			*ft_no_quotes_str(char *str, int *i, t_shell *shell);
char			*ft_singlequotes_str(char *str, int *i);
char			*ft_pwd(void);

/*
** checks for correct input before parsing.
*/

void			ft_set_qts(t_qts *qts);
void			ft_qt_line(char *line, t_qts *qts, int *i);
void			ft_qt_start(char *line, t_qts *qts);
int				ft_backslash_check(char *line, int i);
char			*ft_find_case_cmd(char *cmd);

/*
** parsing functions, command specific functions.
*/

void			minishell_parser(char *line, t_shell *shell, char **envp);
int				ft_echo_parser(char *line, int *i, t_shell *shell);
void			ft_cd(char *str, int *i, t_shell *shell);
void			ft_pwd_main(char *str, int *i, t_shell *shell);
void			ft_rd_parser(char *str, int *i, t_shell *shell);
void			ft_env_parser(char *str, int *i, t_shell *shell);
int				env_main(char *str, t_shell *shell);

/*
** env stuff
*/
void			ft_add_env_back(t_shell *shell, char *input);
int				ft_envlen(t_shell *shell);
int				env_main(char *str, t_shell *shell);

/*
** clear shell struct
*/
void			ft_clear_shell(t_shell *shell);
#endif
