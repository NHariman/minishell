/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execv_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 15:22:12 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/25 18:42:33 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_execv_parser(char *cmd, char *str, int *i, t_shell *shell)
{
	int		start;
	t_qts	qts;
	char	*substr;

	start = *i;
	ft_set_qts(&qts);
	ft_qt_line(str, &qts, i);
	substr = ft_substr(str, start, *i - start);
	ft_execute(cmd, substr, shell);
	free(substr);
	return ;
}