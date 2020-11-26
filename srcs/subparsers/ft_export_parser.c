/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_export_parser.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 20:36:01 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/26 20:41:06 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			ft_export_parser(char *str, int *i, t_shell *shell)
{
	int		start;
	int		check;
	char	*exp_str;
	t_qts	qts;

	start = *i;
	ft_set_qts(&qts);
	ft_qt_line(str, &qts, i);
	exp_str = ft_substr(str, start, *i - start);
	ft_export(exp_str, shell);
	if (ft_strchr("\n;\0", str[*i]) && check == 1)
		ft_printf("%s\n", shell->exp_str);
	free(exp_str);
	return ;
}
