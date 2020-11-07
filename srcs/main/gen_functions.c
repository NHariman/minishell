/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 03:52:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/07 19:30:46 by nhariman      ########   odam.nl         */
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

void	ft_wordlow(char *line, int start)
{
	while (line[start] != '\0')
	{
		if (!ft_isalpha(line[start]))
			break ;
		line[start] = ft_tolower(line[start]);
		start++;
	}
}

char	*ft_find_arg(char *str, int *i)
{
	char	*word;

	while (str[*i] != '\n' && str[*i] != ' ' && ft_isalpha(str[*i]))
		*i = *i + 1;
	word = ft_substr(str, 0, *i);
	return (word);
}
