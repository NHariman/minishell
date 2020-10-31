/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 22:15:37 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_struct_m
{
	char    *cache;
	int     i;
	int     path;
	int     single;
	int     Double;
	int     end;
	int     len;
	int     stat;
}				t_struct_m;

char        *echo_main(char  *str);
int         check_n(char* str);
int     	lenght_n(char* str);
void        no_str(t_struct_m *Echo, char* str);
