/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   niks.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:24:35 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/22 18:19:20 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIKS_H
# define NIKS_H

# define SQ 1
# define DQ 2
# define IN 0
# define OUT 1

typedef struct s_trim
{
	int			start;
	char		*res;
}				t_trim;

/*
** dq: checks for equal amount of double quotes " "
** sq: checks for equal amount of single quotes ' '
*/

typedef struct s_qts
{
	int			dq;
	int			sq;
}				t_qts;

typedef struct s_shell
{
	int			exit_code;
	int			tmp_std[2];
	int			new_fds[2];
	int			is_pipe;
	pid_t		child_pid;
	pid_t		tpid;
	int			child_status;
	char		*home;
	int			argc;
	char		**argv;
	char		*rds;
	char		**env;
}				t_shell;

/*
** input checkers
*/

void			prompt(void);
void			ft_set_qts(t_qts *qts);
void			ft_qt_line(char *line, t_qts *qts, int *i);
void			ft_qt_start(char *line, t_qts *qts);
int				ft_backslash_check(char *line, int i);
int				check_end(char *line);
char			**ft_fill_prompts(char **prompts, char *str,
					int len, char token);
void			ft_make_prompts(char *str);
void			ft_pipe_splitter(char *str);
char			*get_cmd(char *str, int *i);
void			function_dispatcher(char *line);

/*
** prompt functions
*/
char			**ft_get_prompts(char *str);
int				get_file_contents(int fd, char **line);
int				get_next_line_sig(int fd, char **line);
int				get_fill_line_ret(int newline, size_t remainder);
int				get_gnl_ret(int newline, char *leftover, int ret);
char			*get_line_read(char *tmp);
int				make_argv_rd(char *line);
char			**ft_argv(char *str);
int				ft_count_arr(char *str);
char			*trim_rd(char *line);
char			*ft_get_rdin(char *str);

/*
** quotes parsing.
*/
void			ft_tilde_expansion(t_trim *trim, int *i, char *str);
void			check_quotes(char *str, int *i, t_trim *trim);
char			*ft_insert_nqt_output(t_trim *trim);
void			ft_nqts_dq_strjoin(char *str, int *i, t_trim *trim);
void			ft_skip_quotes(char *str, int *i, char type);
void			ft_nqts_sq_strjoin(char *str, int *i, t_trim *trim);
void			ft_nqts_nqts_strjoin(char *str, int *i, t_trim *trim);
void			ft_strspecial(char *str, t_trim *trim, int *i, char c);
void			ft_parse_dollar(char *str, int *i, t_trim *trim);
char			*ft_doublequotes_str(char *str, int *i);
char			*ft_no_quotes_str(char *str, int *i, char *stop);
char			*ft_singlequotes_str(char *str, int *i);
int				ft_qt_check(char *line, int *i, int type, t_qts *qts);
void			ft_skip_rd(char *str, int *i);

/*
** parsing functions, command specific functions.
*/

void			ft_echo(void);
void			ft_cd(void);
void			ft_pwd_main(void);
void			ft_rd_parser(char *str, int *i);
char			*ft_pwd(void);
int				get_exit_code(int status);
void			ft_exit_minishell(char **arr, int len);

/*
** env
*/

void			ft_env(void);
char			*ft_find_variable(char *str, int *i);
char			*ft_find_envvar(char *var);

/*
** execve/execute functions
*/

int				ft_is_directory(char *cmd);
int				ft_ispath(char *cmd);
void			increase_shlvl(void);
char			**ft_path_array(char *str, char *cmd);
void			ft_execute(char *cmd);
int				ft_execve(char **argv);

/*
** export
*/

void			ft_export(void);
int				*ft_order_env(char **env);
void			ft_sort_env(int *order, char **env, int start);
char			*ft_parse_env_str(int *order, char **env);
char			*ft_add_quotations(char *str, int start);
void			ft_update_env(char *str);
int				ft_valid_envvar(char *str);
char			*ft_find_varname(char *str);

/*
** pipes
*/

void			pipe_child(int **p, char **pipes, int i);
void			pipe_parent(int *i, int **p, char **pipes, pid_t pid);
void			free_p(int **p, int len);

/*
** unset
*/

void			ft_delete_env(char *input);
void			ft_unset(void);

/*
** clear shell struct
*/
void			save_std(int *og_std);
void			restore_std(int *og_std);
void			wait_for_process(void);
void			ft_clear_shell(void);
void			ft_wordparser(void);
int				free_and_return(char *str, int ret);

/*
** fatal errors
*/
void			ft_malloc_fail(char *str);
void			error_exit(char *str, int nb);
#endif
