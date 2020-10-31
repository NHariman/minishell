/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_parsers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:43:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/10/31 21:50:39 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** receives the string past the echo, need to trim away pipe functions.
*/
int		ft_echo_parser(char *line)
{
	ft_printf("%s\n", line);
	return (0);
}