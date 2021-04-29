/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wordparser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:08:40 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/29 13:00:25 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** " " preserves literal value of all characters within the quotes
** with the exception of $, ` and \.
** ` and $ retain special meaning
** \ only retains meaning if followed by ` $ " \.
** ^ backslacshes that are followed by one of these characters are removed.
** backslash preceeding characters without a special meaning are left
** unmodified.
*/

char	*get_cmd(char *str, int *i)
{
	char	*cmd;

	*i = *i + ft_iswhitespaces(str + *i);
	if (str[*i] == '$' && str[*i + 1 + ft_iswhitespaces(str + (*i + 1))] == '\0')
		cmd = ft_make_single_char_str(str[*i]);
	else
	{
		cmd = ft_no_quotes_str(str, i, " ");
		if (ft_strchr(cmd, '=') != NULL)
		{
			ft_printf_err(
				"Nonexplicit environment variable adding not supported.\n");
			while (str[*i] != '\0')
			{
				free(cmd);
				while (str[*i] == ' ')
					*i = *i + 1;
				if (str[*i] != '\0')
					cmd = ft_no_quotes_str(str, i, " ");
				if (!ft_strchr(cmd, '='))
					break ;
			}
		}
	}
	return (cmd);
}

static void	ft_check_case(void)
{
	if (!ft_strcmp(g_shell.argv[0], "echo"))
		ft_echo();
	else if (!ft_strcmp(g_shell.argv[0], "env"))
		ft_env();
	else if (!ft_strcmp(g_shell.argv[0], "pwd"))
		ft_pwd_main();
	else
		ft_execute(g_shell.argv[0]);
}

void	ft_wordparser(void)
{
	if (g_shell.argv[0] == NULL)
		return ;
	if (!ft_strcmp(g_shell.argv[0], "exit"))
		ft_exit_minishell(g_shell.argv, ft_arrlen(g_shell.argv));
	else if (!ft_strcmp(g_shell.argv[0], "export"))
		ft_export();
	else if (!ft_strcmp(g_shell.argv[0], "unset"))
		ft_unset();
	else if (!ft_strcmp(g_shell.argv[0], "cd"))
		ft_cd();
	else if (ft_strchr("eEpP", g_shell.argv[0][0]))
		ft_check_case();
	else
		ft_execute(g_shell.argv[0]);
}
