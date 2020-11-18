/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 18:55:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "niks.h"

typedef struct	s_struct_m
{
	char		*str;
	char		*cache;
	char		*tmp;
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
	int			single;
	int			doubble;
	int			len;
	char		*cache;
	char		*string;
	char		*file;
	char		*str;

	int			echo;
	int			variable;
	int			txt;
	int			dir;
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
char		*rd_main(char *str, t_struct_rd *rd, t_shell *shell);
void		set_value_rd(t_struct_rd *rd);
int			start_rd(t_struct_rd *rd, t_shell *shell);
char		*cut_string_shell(char *str, t_struct_rd *rd, t_shell *shell);
void		cut_string_shell_len(char *str, t_struct_rd *rd, t_shell *shell);
int			rd_loop(t_struct_rd *rd, t_shell *shell);
char   		*ft_add_variables_rd(char *str, t_struct_rd *rd, t_shell *shell);
int			ft_check_rd(t_struct_rd *rd, t_shell *shell);
int			ft_check_rd_echo(t_struct_rd *rd, t_shell *shell);

//functions
void		ft_trim_single_c(t_struct_m *echo);
