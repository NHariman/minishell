/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:08:40 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/12 23:43:40 by nhariman      ########   odam.nl         */
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
		while (cmd != NULL && ft_strchr(cmd, '=') != NULL)
		{
			free(cmd);
			ft_printf_err(
				"Nonexplicit environment variable adding not supported.\n");
			cmd = NULL;
			while (str[*i] == ' ')
				*i = *i + 1;
			if (str[*i] != '\0')
				cmd = ft_no_quotes_str(str, i, " ");
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
	if (g_shell.rds)
		free(g_shell.rds);
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

void	function_dispatcher(char *line)
{
	int	og_std[2];

	make_argv_rd(line);
	save_std(og_std);
	g_shell.tmp_std[IN] = og_std[IN];
	int i = 0;
	while (g_shell.argv[i] != (char *) 0)
	{
		ft_printf("g_shell.argv[%i]: %s\n", i, g_shell.argv[i]);
		i++;
	}
	if (g_shell.rds)
		rd_main(g_shell.rds);
	ft_wordparser();
	restore_std(og_std);
	if (g_shell.child_pid != -2)
		wait_for_process();
}

void	minishell_parser(char *line)
{
	if (line[0] == '\0' || syntax_check(line))
		return ;
	ft_make_prompts(line);
}
