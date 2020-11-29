/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:08:40 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/29 03:49:02 by nhariman      ########   odam.nl         */
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

static char		*get_cmd(char *str, int *i, t_shell *shell)
{
	char	*cmd;

	cmd = ft_no_quotes_str(str, i, shell);
	while (ft_strchr(cmd, '=') != NULL)
	{
		free(cmd);
		while (str[*i] == ' ')
			*i = *i + 1;
		cmd = ft_no_quotes_str(str, i, shell);
	}
	return (cmd);
}

static void		ft_check_case(char *cmd, char *line, int *i, t_shell *shell)
{
	if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
		ft_echo_parser(line, i, shell);
	else if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
		ft_env_parser(line, i, shell);
	else if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		ft_pwd_main(line, i, shell);
	else
		ft_execv_parser(cmd, line, i, shell);
}

static void		ft_wordparser(char *line, int *i, t_shell *shell)
{
	char	*cmd;

	cmd = NULL;
	if (line[*i] == '\0')
		return ;
	cmd = get_cmd(line, i, shell);
	if (!ft_strncmp(cmd, "exit", ft_strlen(cmd)))
		exit_minishell(line, i, shell);
	else if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
		ft_export_parser(line, i, shell);
	else if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
		ft_unset_parser(line, i, shell);
	else if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		ft_cd(line, i, shell);
	else if (ft_strchr("eEpP", cmd[0]))
		ft_check_case(cmd, line, i, shell);
	else
		ft_execv_parser(cmd, line, i, shell);
}

static void		function_dispatcher(char *line, t_shell *shell)
{
	int		i;
	char	*cmd;
	char	**tmp;

	i = 0;
	cmd = get_cmd(line, &i, shell);
	tmp = ft_argv(line + i, shell);
	if (!tmp)
		shell->argv = empty_array(cmd);
	else
		shell->argv = ft_add_arr_front(tmp, cmd);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		i = i + ft_iswhitespaces(line + i);
		ft_wordparser(line, &i, shell);
		if (line[i] == '>')
			ft_rd_parser(line, &i, shell);
		if (line[i] == '<')
			ft_rd_parser(line, &i, shell);
		if (line[i] == '|')
			ft_printf("pipe function here, |, takes the shell struct\n");
		i++;
	}
}

void			minishell_parser(char *line, t_shell *shell)
{
	t_qts		qts;
	int			i;
	char		**prompts;

	i = 0;
	prompts = (char **)0;
	ft_set_qts(&qts);
	ft_qt_start(line, &qts);
	if (qts.dq % 2 != 0 || qts.sq % 2 != 0)
		ft_printf_err("Error\nHanging quotes. Parsing failed.\n");
	else
	{
		prompts = ft_get_prompts(line);
		int k = 0;
		while (prompts[k] != (char *)0)
		{
			ft_printf("prompts: %s\n", prompts[k]);
			k++;
		}
		while (prompts[i] != (char *)0)
		{
			function_dispatcher(prompts[i], shell);
			ft_clear_shell(shell);
			i++;
		}
		ft_free_array(prompts, ft_arrlen(prompts));
	}
	free(line);
}
