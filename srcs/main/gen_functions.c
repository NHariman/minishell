/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 03:52:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/06 20:27:57 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_rm_endline(char *str)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = ft_substr(str, 0, len - 1);
	free(str);
	return (new);
}

char	*ft_find_arg(char *str, int *i)
{
	char	*word;

	while (str[*i] != '\n' && ft_isalpha(str[*i]))
		*i = *i + 1;
	word = ft_substr(str, 0, *i);
	return (word);
}
