/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 15:00:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef YUSHA_H
# define YUSHA_H

# include "niks.h"

typedef struct s_struct_m
{
	char		*str;
	char		*cache;
	char		*tmp;
	int			flag;
	int			n;
	int			i;
	int			s;
}				t_struct_m;

typedef struct s_struct_tr
{
	int			begin;
	int			end;
	int			single;
	int			doubble;
	int			quote;
	int			empty;
	int			error;
	int			flag;
	char		*s_str;
	char		*s_tmp;
	char		*s_cache;
	char		*s_begin;
	char		*s_end;
	char		*s_variable;
	char		*e_check;
}				t_struct_tr;

typedef struct s_struct_rd
{
	int			i;
	int			error;
	int			fd;
	int			fd_rd;
	int			nb;
	int			rdi;

	char		*cache;
	char		*tmp;
	char		*file;
	char		*str;
}				t_struct_rd;

//echo main
char	*echo_main(char *str, t_struct_m *echo);
int		skip_character(char *str, int i, char c);
int		check_flag_n(t_struct_m *echo);
void	set_value_echo(t_struct_m *echo);
void	ft_trim_backslash(t_struct_m *echo);

//handle quotes
void	ft_handle_quotes(t_struct_m *echo);

//struct clean
void	set_value_echo(t_struct_m *echo);
void	set_value_trim(t_struct_tr *trim);

//variables
void	ft_add_variables(t_struct_m *echo);
void	ft_get_variable(t_struct_tr *trim);
void	ft_split_variable(t_struct_tr *trim);
void	ft_add_variables_double(t_struct_m *echo);

//functions
void	ft_trim_single_c(t_struct_m *echo);
char	*ft_strcpystr(int start, char *str, char c);

//synax
int		syntax_check(char *line);
int		check_red_1(char *line);
int		check_red_2(char *line);
int		rd_syntax_error(char *line, int i, int len);
int		rd_syntax_error_left(char *line, int i);
int		rd_syntax_error_right(char *line, int i);

//signals
void	handle_signals(int sign);
void	ignore_signal(int sign);
void	ft_signals_control(void);

//rd
void	rd_main(char *str);
int		get_check_redirect(t_struct_rd *rd);

int		rd_loop(t_struct_rd *rd);
int		rd_get_nb(t_struct_rd *rd);
void	rd_get_file(t_struct_rd *rd);
void	rd_open_file(t_struct_rd *rd);
void	rd_open_file_fill(t_struct_rd *rd);

#endif
