/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/07 19:24:14 by ybakker       ########   odam.nl         */
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

typedef struct	s_struct_t
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
}				t_struct_t;

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
	char*		s_str;
	char*		s_tmp;
	char*		s_cache;
	char*		s_begin;
	char*		s_end;
}				t_struct_q;

//echo main
char		*echo_main(char *str, t_struct_m *echo);
int			skip_character(char *str, int i, char c);
int		check_flag_n(t_struct_m *echo);
void        set_value_echo(t_struct_m *echo);

//struct clean
void        set_value_echo(t_struct_m *echo);
void        set_value_trim(t_struct_t *trim);
void		set_value_empty(t_struct_e *empty);
void		set_value_han(t_struct_q *han);

//variables
void    	ft_add_variables(t_struct_m *echo);

//empty lines
void		ft_empty_lines(t_struct_m *echo);

//handle quotes
void        ft_handle_quotes(t_struct_m *echo);
