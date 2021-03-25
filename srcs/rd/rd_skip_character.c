/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_skip_character.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 12:14:33 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 13:27:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int	skip_character(char *str, int i, char c)
{
	while (str[i] == c && (str[i]))
	{
		i++;
	}
	return (i);
}
