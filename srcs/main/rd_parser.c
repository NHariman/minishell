/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_parser.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 18:26:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/21 21:40:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_rd_parser(char *str, int *i, t_shell *shell)
{
	int		start;
	char	*rd_str;
	t_qts	qts;

	start = *i;
	while (str[*i] != '\n' && str[*i] != '\0' && !ft_strchr("|;", str[*i]))
		*i = *i + 1;
	if (start == *i || *i == 0)
		rd_str = ft_strdup("\n");
	else
		rd_str = ft_substr(str, start, *i - start);
	shell->rd_r = ft_strdup(rd_main(rd_str, shell));
	shell->check.rd = 1;
	if (ft_strchr("\n;\0", str[*i]))
		ft_rd_output(shell->rd_r, shell);
}
