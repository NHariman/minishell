/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 15:33:26 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 19:34:39 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_line_read(char *tmp)
{
	char	*out;

	if (!tmp)
		return (NULL);
	out = ft_strdup(tmp);
	return (out);
}

int	get_fill_line_ret(int newline, size_t remainder)
{
	if (newline != -1 && remainder)
		return (1);
	return (0);
}

int	get_gnl_ret(int newline, char *leftover, int ret)
{
	if (newline != -1 && !leftover)
		return (-1);
	return (ret);
}
