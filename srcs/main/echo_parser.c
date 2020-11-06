/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_parsers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:43:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/06 01:47:08 by nhariman      ########   odam.nl         */
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

static	int		ft_q_check(char *line, int *i, int type, t_echo *qts)
{
	ft_set_qts(qts);
	*i = *i + 1;
	while (line[*i] != '\0' && line[*i] != '\n')
	{
		if ((line[*i] == '\'' && type == SQ) ||
		(line[*i] == '\"' && type == DQ))
		{
			ft_printf("test\n");
			return (0);
		}
		*i = *i + 1;
	}
	return (1);
}

static	void	ft_echo_line(char *line, t_echo *qts, int *i)
{
	while (line[*i] != '\0' && line[*i] != '\n')
	{
		if (ft_strchr(">|;<", line[*i]))
			return ;
		else if (line[*i] == '\'')
			qts->sq = ft_q_check(line, i, SQ, qts);
		else if (line[*i] == '\"')
			qts->dq = ft_q_check(line, i, DQ, qts);
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
	if (qts.dq % 2 != 0 || qts.sq % 2 != 0)
		return (ft_printf("Error\nHanging quotes. Echo failed.\n"));
	if (ft_strchr(">|;\'\"<", line[i]) && i == 0)
		echo_str = ft_strdup("");
	else if (ft_strchr(">|;\'\"<", line[i]) && i > 0)
		echo_str = ft_substr(line, 0, i - 1);
	else
		echo_str = ft_substr(line, 0, i);
	echo_main(echo_str);
	//free (echo);
	return (0);
}
