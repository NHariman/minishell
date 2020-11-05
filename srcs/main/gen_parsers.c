/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_parsers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:43:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/05 19:21:17 by nhariman      ########   odam.nl         */
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

static	void	ft_echo_line(char *line, t_echo *qts, int *i)
{
	while (line[*i] != '\0')
	{
		if ((qts->sq == 2 && qts->dq == 1) || (qts->sq == 1 && qts->dq == 2))
			ft_set_qts(qts);
		if ((ft_strchr(">|<", line[*i]) && qts->dq != 0 && qts->sq != 0 &&
		qts->dq % 2 == 0 && qts->sq % 2 == 0) ||
		((ft_strchr(">|<", line[*i]) && !qts->dq && !qts->sq)))
			return ;
		else if (line[*i] == '\'')
			qts->sq++;
		else if (line[*i] == '\"')
			qts->dq++;
		*i = *i + 1;
	}
}

int				ft_echo_parser(char *line)
{
	int		i;
	t_echo	qts;
	char	*echo_str;

	i = 0;
	ft_set_qts(&qts);
	ft_echo_line(line, &qts, &i);
	ft_printf("dq: %i\nsq: %i\n", qts.dq, qts.sq);
	if ((!qts.dq && qts.sq % 2 != 0) || (qts.dq % 2 != 0 && !qts.sq) ||
		(qts.dq && qts.sq) || (qts.dq % 2 != 0 && qts.sq))
		return (ft_printf("Error\nHanging quotes. Echo failed.\n"));
	echo_str = ft_strchr(">|<", line[i]) ?
				ft_substr(line, 0, i) : ft_substr(line, 0, i - 1);
	echo_main(echo_str);
	return (0);
}
