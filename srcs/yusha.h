/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   yusha.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:35:31 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 21:25:18 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*Echo functions */

typedef struct	s_struct_m
{
    char*   cache = ft_strdup("");
    int     i       = 0;
    int     path    = 0;
    int     single  = 0;
    int     Double  = 0;
    int     end     = 0;
    int     len     = 0;
}				t_struct_m;

void        echo_main(char* str);