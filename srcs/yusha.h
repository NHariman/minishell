/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/04 10:51:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef YUSHA_H
# define YUSHA_H

# include "niks.h"

typedef struct	s_struct_m
{
	char		*str;
	char		*cache;
	char		*tmp;
	int			flag;
	int			n;
	int			i;
	int			s;
}				t_struct_m;

typedef struct	s_struct_tr
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

typedef struct	s_struct_e
{
	int			begin;
	int			end;
	int			single;
	int			doubble;
	char		*s_str;
	char		*s_tmp;
	char		*s_cache;
	char		*s_begin;
	char		*s_end;
}				t_struct_e;

typedef struct	s_struct_rd
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
char       *echo_main(char *str, t_struct_m *echo, t_shell *shell);
int			skip_character(char *str, int i, char c);
int			check_flag_n(t_struct_m *echo);
void        set_value_echo(t_struct_m *echo);
void		ft_trim_backslash(t_struct_m *echo);

//handle quotes
void        ft_handle_quotes(t_struct_m *echo);

//struct clean
void        set_value_echo(t_struct_m *echo);
void        set_value_trim(t_struct_tr *trim);

//variables
void    	ft_add_variables(t_struct_m *echo, t_shell *shell);
void		ft_get_variable(t_struct_tr *trim, t_shell *shell);
void		ft_split_variable(t_struct_tr *trim, t_shell *shell);
void    	ft_add_variables_double(t_struct_m *echo, t_shell *shell);

//redirect
void		rd_main(char *str, t_shell *shell);
void    	rd_value_rd(t_struct_rd *rd);
int     	rd_loop(t_struct_rd *rd, t_shell *shell);
int     	rd_get_nb(t_struct_rd *rd);
void    	rd_open_file_fill(t_struct_rd *rd, t_shell *shell);
void		rd_open_file(t_struct_rd *rd, t_shell *shell);

//rd check
int			error_check_rd(t_struct_rd *rd, t_shell *shell);
void 		rd_get_file(t_struct_rd *rd, t_shell *shell, t_struct_m	*echo);


//functions
void		ft_trim_single_c(t_struct_m *echo);
char		*ft_strcpystr(int start, char *str, char c);


//synax
int     	syntax_check(char *line, t_shell *shell);

//signals
void    	handle_hangup(int sign);
#endif
