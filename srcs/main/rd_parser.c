/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_parser.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 18:26:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/15 19:03:18 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_rd_parser(char *str, int *i, t_shell *shell)
{
	int		start;
	char	*rd_str;

	start = *i;
	while (str[*i] != '\n' && str[*i] != '\0' && str[*i] != ';')
		*i = *i + 1;
	if (start == *i || *i == 0)
		rd_str = ft_strdup("\n");
	else
		rd_str = ft_substr(str, start, *i - start);
	rd_main(rd_str, shell);
}
