/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_parsers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:43:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/05 14:39:02 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** receives the string past the echo, need to trim away pipe functions.
** example:
** -n string "string < dsthdf" 'dfdkfhaf >'  > file
** should send everything until              ^ this character.
** test string, good: echo "test >" '<'       "test | " < test
** test string, bad: echo "test >" '<       "test | " < test
*/

static void		ft_set_qts(t_echo *qts)
{
	qts->dq = 0;
	qts->sq = 0;
}

int				ft_echo_parser(char *line)
{
	int		i;
	t_echo	qts;
	char	*echo_str;

	i = 0;
	ft_set_qts(&qts);
	while (line[i] != '\0')
	{
		if (ft_strchr(">|<", line[i]) && qts.dq != 0 && qts.sq != 0 &&
		qts.dq % 2 == 0 && qts.sq % 2 == 0)
			break ;
		else if (line[i] == '\'')
			qts.sq++;
		else if (line[i] == '\"')
			qts.dq++;
		i++;
	}
	if ((qts.dq != 0 && qts.dq % 2 != 0) || (qts.sq != 0 && qts.sq % 2 != 0))
		return (ft_printf("Error\nUneven amount of quotes. Echo failed.\n"));
	echo_str = ft_strchr(">|<", line[i]) ?
				ft_substr(line, 0, i) : ft_substr(line, 0, i - 1);
	echo_main(echo_str);
	return (0);
}
