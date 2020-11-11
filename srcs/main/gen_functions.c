/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 03:52:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/08 19:19:23 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_rm_endline(char *str)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = ft_substr(str, 0, len - 1);
	return (new);
}

int		exit_minishell(void)
{
	ft_printf("exit\n");
	exit(0);
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
	int		start;
	t_qts	qts;

	start = *i;
	while (!ft_strchr(" \n", str[*i]) && str[*i] != '\0')
		*i = *i + 1;
	word = ft_substr(str, start, *i - start);
	word = ft_strtrim(word, "\"\'");
	ft_set_qts(&qts);
	ft_qt_line(str, &qts, i);
	while (!ft_strchr("$><;| \n\0", str[*i]))
		*i = *i + 1;
	return (word);
}
