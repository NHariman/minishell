/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:08:40 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/14 19:09:54 by nhariman      ########   odam.nl         */
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

static char	*get_cmd(char *str, int *i, t_shell *shell)
{
	char	*cmd;
	int		start;

	start = *i + 1;
	if (str[*i] == '\'')
	{
		*i = *i + 1;
		while (str[*i] != '\'')
			*i = *i + 1;
		cmd = ft_substr(str, start, *i - start);
		*i = *i + 1;
	}
	else if (str[*i] == '\"' && ft_backslash_check(str, *i) % 2 == 0)
		cmd = ft_doublequotes_str(str, i, shell);
	else
		cmd = ft_no_quotes_str(str, i, shell);
	return (cmd);
}

static void	ft_wordparser(char *line, int *i, t_shell *shell)
{
	char	*cmd;

	cmd = NULL;
	if (line[*i] == '\n' || line[*i] == '\0')
		return ;
	cmd = get_cmd(line, i, shell);
	if (ft_strchr("eEpP", cmd[0]))
		ft_find_echo_pwd(&cmd);
	if (!ft_strncmp(cmd, "export", ft_strlen(cmd)) && strlen(cmd) == ft_strlen("export"))
		ft_printf("export function here\n");
	else if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)) && strlen(cmd) == ft_strlen("echo"))
		ft_echo_parser(line, i, shell);
	else if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)) && strlen(cmd) == ft_strlen("cd"))
		ft_cd(line);
	else if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)) && strlen(cmd) == ft_strlen("pwd"))
	{
		ft_printf("%s\n", ft_pwd());
	}
	else if (cmd == NULL)
		shell->err = ft_strdup("");
	else
		ft_printf("minishell: %s: command not found\n",
			ft_find_arg(cmd, line, i));
}

/*
** TODO: find word and create string until the end or if it finds a
** >> > < | ;
** create the line BEFORE you send it to the main function.
** so you can also create command not found accurately.
*/

/*
** find cmd and save it in args->cmd
** fid line it should execute and send it to args->str
*/

static void	function_dispatcher(char *line, t_shell *shell)
{
	int 	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		while (line[i] == ' ')
			i++;
		if (!ft_strncmp(line + i, "exit\n", ft_strlen("exit\n")) ||
			!ft_strncmp(line + i, "exit ", ft_strlen("exit ")))
			exit_minishell();
		if (!ft_strchr("$><;|\n\0", line[i]))
			ft_wordparser(line, &i, shell);
		if (line[i] == '$')
			ft_printf("env: %s\n", ft_find_variable(line, &i, shell));
		if (line[i] == '.')
			ft_printf("filename argument execute, execv()\n");
		if (line[i] == '>')
			ft_printf("pipe function here, should handle > and >>, takes the shell struct and line starting from first >\n");
		if (line[i] == '<')
			ft_printf("pipe function here, should handle <, takes the shell struct\n");
		if (line[i] == '|')
			ft_printf("pipe function here, |, takes the shell struct\n");
		if (line[i] == ';' || line[i] == '\n' || line[i] == '\0')
			ft_printf("");
		i++;
	}
}

void		minishell_parser(char *line, char **envp)
{
	t_shell		*shell;
	t_qts		qts;

	shell = calloc(1, sizeof(t_shell));
	shell->env = envp;
	ft_set_qts(&qts);
	ft_qt_start(line, &qts);
	if (qts.dq % 2 != 0 || qts.sq % 2 != 0)
		ft_printf("Error\nHanging quotes. Parsing failed.\n");
	else
		function_dispatcher(line, shell);
}
