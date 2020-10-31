/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 21:49:21 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_struct_m
{
    char    *cache = ft_strdup("");
    int     i       = 0;
    int     path    = 0;
    int     single  = 0;
    int     Double  = 0;
    int     end     = 0;
    int     len     = 0;
    int     stat    = 0;
}				t_struct_m;

char        *echo_main(char  *str);
int         check_n(char* str);
void    no_str(t_struct_m *Echo, char* str);
