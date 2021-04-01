/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 16:27:15 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef YUSHA_H
# define YUSHA_H

# include "niks.h"

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
void	rd_get_file_name(t_struct_rd *rd);
void	rd_open_file(t_struct_rd *rd);
void	rd_open_file_fill(t_struct_rd *rd);

#endif
