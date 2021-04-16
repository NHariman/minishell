/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/15 14:14:01 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

void    open_check(void)
{
    int inn = 0;
    int out = 0;

    inn = open("filecheck2", O_RDONLY);
    out = open("filecheck1", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    ft_printf("IN = [%i] OUT = [%i]\n", inn, out);
    ft_printf("IN = [%i] OUT = [%i]\n", read(inn, NULL, 0), read(out, NULL, 0));
    close(inn);
    close(out);
}