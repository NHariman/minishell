/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 08:12:33 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/18 13:33:39 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//| ; < > << \ (syntax errors)

int				check_red_1(char *line)
{
    int     i;
    int len;

    len = 0;
    i = 0;
	while (line[i])
	{
        if (line[i] == '>')
        {
            while (line[i] == '>')
            {
                len++;
                i++;
            }
            if (len == 3)
            {
                ft_printf("bash: syntax error near unexpected token `>'\n");
                shell.exit_code = 1;
                return (-1);
            }
            else if (len > 3)
            {
                ft_printf("bash: syntax error near unexpected token `>>'\n");
                shell.exit_code = 1;
                return (-1);
            }
        }
		i++;
        len = 0;
	}
    return (0);
}

int				check_red_2(char *line)
{
    int     i;
    int len;

    len = 0;
    i = 0; 
    while (line[i])
	{
        if (line[i] == '<')
        {
            while (line[i] == '<')
            {
                len++;
                i++;
            }
            if (len == 1)
		        return (0);
            else if (len > 2 && len < 4)
                ft_printf("bash: syntax error near unexpected token `<'\n");
            else if (len == 5)
                ft_printf("bash: syntax error near unexpected token `<<'\n");
            else if (len >= 6)
                ft_printf("bash: syntax error near unexpected token `<<<'\n");
            shell.exit_code = 1;
            return (-1);
        }
		i++;
        len = 0;
	}
    return (0);
}

int check_bs(char *line)
{
    int i;

    i = 0;

    while (line[i])
    {
        if (line[i] == '\\')
        {
            ft_printf("minishell: syntax error near unexpected token '\'\n");
            shell.exit_code = 1;
            return (-1);
        }
        i++;
    }
    return (0);
}

int     syntax_check(char *line)
{
    if (check_end(line) || check_red_1(line) || check_red_2(line) || check_bs(line))
    {
        ft_printf("an error has occured\n");
        return (shell.exit_code);
    }
    return (0);
}