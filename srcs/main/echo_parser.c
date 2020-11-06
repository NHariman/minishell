/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 23:38:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/06 23:38:16 by nhariman      ########   odam.nl         */
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

static void			free_echo_struct(t_struct_m *echo)
{
	free(echo->cache);
	free(echo->str);
	free(echo);
}

int					ft_echo_parser(char *line, int *i, t_shell *shell)
{
	int			start;
	t_qts		qts;
	char		*echo_str;
	t_struct_m	*echo;

	start = *i + ft_strlen("echo ");
	*i = *i + ft_strlen("echo ");
	echo = ft_calloc(1, sizeof(t_struct_m));
	if (echo == NULL)
		return (0);
	ft_set_qts(&qts);
	ft_qt_line(line, &qts, i);
	if (qts.dq % 2 != 0 || qts.sq % 2 != 0)
		return (ft_printf("Error\nHanging quotes. Echo failed.\n"));
	if (ft_strchr(">|;\'\"<", line[*i]) && *i == start)
		echo_str = ft_strdup("");
	else if (ft_strchr(">|;\'\"<", line[*i]))
		echo_str = ft_substr(line, start, *i - 1 - start);
	else
		echo_str = ft_substr(line, start, *i - start);
	*i = *i + ft_strlen(echo_str);
	shell->echo = ft_strdup(echo_main(echo_str, echo));
	free_echo_struct(echo);
	return (0);
}
