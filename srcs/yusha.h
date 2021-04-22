/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/22 09:19:45 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef YUSHA_H
# define YUSHA_H

# include "niks.h"

typedef struct s_struct_rd
{
	int			i;
	int			error;
	int			out;
	int			in;
	int			nb;
	int			rdi;
	int 		store;

	char		*cache;
	char		*tmp;
	char		*file;
	char		*str;
}				t_struct_rd;

//synax
int		syntax_check(char *line);
int		check_red_one(char *line);
int		check_red_two(char *line);
int		rd_syntax_error(char *line, int i, int len);
int		rd_syntax_error_left(char *line, int i);
int		rd_syntax_error_right(char *line, int i);

int		check_red_one_error(int len);
int		check_red_two_error(int len);
int		check_rd_right(char *line, int i);
int		check_rd_left(char *line, int i);
int		check_rd_newline(char *line, int i, char c);

int		check_end(char *line);
int		syntax_full_check(char *line);
int		check_front_token(char *line, int i);
int		is_token(char c);
int		ft_semicol_err(void);
int 	syntax_pipes(char *line, int i);

//signals
void	handle_signals(int sign);
void	ignore_signal(int sign);
void	ft_signals_control(void);

//rd
int		rd_main(char *str, int *new_fds);
int		get_check_redirect(t_struct_rd *rd);

int		rd_loop(t_struct_rd *rd, int *new_fds);
int		rd_get_nb(t_struct_rd *rd);
void	rd_get_file_name(t_struct_rd *rd);
void	rd_open_file(t_struct_rd *rd);
void	rd_open_file_fill(t_struct_rd *rd, int *new_fds);
void	restore_fds(int *new_fds);
#endif
