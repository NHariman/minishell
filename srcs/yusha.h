/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/11 09:50:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_struct_m
{
	char*		str;
	char*		cache;
	char*		tmp;
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
	char*		s_str;
	char*		s_tmp;
	char*		s_cache;
	char*		s_begin;
	char*		s_end;
	char*		s_variable;
	char*		e_check;
}				t_struct_tr;

typedef struct	s_struct_e
{
	int			begin;
	int			end;
	int			single;
	int			doubble;
	char*		s_str;
	char*		s_tmp;
	char*		s_cache;
	char*		s_begin;
	char*		s_end;
}				t_struct_e;

typedef struct	s_struct_q
{
	int			begin;
	int			end;
	int			single;
	int			doubble;
	int			i;
	int			error;
	int			len;
	int			y;
	char*		s_str;
	char*		s_tmp;
	char*		s_cache;
	char*		s_begin;
	char*		s_end;
	char*		s_store;
}				t_struct_q;

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
	int			exit;
	char		*echo;
	char		*pwd;
	char		**env;
	char		*pipe;
	char		**exprt;

}				t_shell;

//echo main
char       *echo_main(char  *str, t_struct_m *echo, t_shell *shell);
int			skip_character(char *str, int i, char c);
int			check_flag_n(t_struct_m *echo);
void        set_value_echo(t_struct_m *echo);

//struct clean
void        set_value_echo(t_struct_m *echo);
void        set_value_trim(t_struct_tr *trim);
void		set_value_empty(t_struct_e *empty);
void		set_value_han(t_struct_q *han);

//variables
void    	ft_add_variables(t_struct_m *echo, t_shell *shell);
void		ft_get_variable(t_struct_tr *trim, t_shell *shell);
void		ft_split_variable(t_struct_tr *trim, t_shell *shell);
//empty lines
void		ft_empty_lines(t_struct_m *echo);

//handle quotes
void        ft_handle_quotes(t_struct_m *echo);
void		echo_no_str(t_struct_q *han);
void		ft_check_back_no(char *str, int i, t_struct_q *han);
void		ft_check_end_no(char *str, int i, t_struct_q *han);
void		echo_double_str(t_struct_q *han);
void		echo_single_str(t_struct_q *han);
void		ft_check_end_double(char *str, int i, t_struct_q *han);
void		ft_check_back_double(char *str, int i, t_struct_q *han);
