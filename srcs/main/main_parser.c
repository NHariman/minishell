/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:08:40 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/12 22:13:48 by nhariman      ########   odam.nl         */
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

// static char	*get_cmd(char *str, int i)
// {
// 	int start;

// 	start = i;
// 	if (str[i] == '\'')
// 	{
// 		i++;
// 		while (str[i] != '\'')
// 			i++;
// 	}
// 	if (str[i] == '\"')
// 	{
// 		i++;
// 		while (str[i] != '\"')
// 			i++;
// 		if (str[i] == '\"' && ft_backslash_check(str, i) % 2 == 0)
// 	}
// 	else
// 	{
// 		// if \ then ensure that whatever comes after it is printed
// 		// if it finds a $ expand that, if it exist it's the first argument.
// 		// if it doesn't exist, look for the next word
// 	}
	
// }

// static void	ft_wordparser(char *line, int *i, t_shell *shell)
// {
// 	char	*cmd;

// 	cmd = NULL;
// 	if (line[*i] == '\n' || line[*i] == '\0')
// 		return ;
// 	cmd = get_cmd(line, *i, shell);
// 	if (!ft_strncmp(cmd, "export ", ft_strlen("export ")) ||
// 		!ft_strncmp(cmd, "export\n", ft_strlen("export\n")))
// 		ft_printf("export function here\n");
// 	if (ft_strchr("eEpP", line[*i]))
// 		ft_wordlow(line, *i);
// 	if (!ft_strncmp(cmd, "echo ", ft_strlen("echo ")))
// 		ft_echo_parser(line, i, shell);
// 	if (!ft_strncmp(cmd, "cd ", ft_strlen("cd ")) ||
// 		!ft_strncmp(cmd, "cd\n", ft_strlen("cd\n")))
// 		ft_cd(line, i);
// 	if (!ft_strncmp(cmd, "pwd ", ft_strlen("pwd ")) ||
// 		!ft_strncmp(cmd, "pwd\n", ft_strlen("pwd\n")))
// 	{
// 		*i = *i + 4;
// 		ft_printf("%s\n", ft_pwd());
// 	}
// 	else
// 		ft_printf("minishell: %s: command not found\n",
// 			ft_find_arg(line, i));
// }

static void	ft_wordparser(char *line, int *i, t_shell *shell)
{
	if (!ft_strncmp(line + *i, "export ", ft_strlen("export ")) ||
		!ft_strncmp(line + *i, "export\n", ft_strlen("export\n")))
		ft_printf("export function here\n");
	if (ft_strchr("eEpP", line[*i]))
		ft_wordlow(line, *i);
	if (!ft_strncmp(line + *i, "echo ", ft_strlen("echo ")))
		ft_echo_parser(line, i, shell);
	else if (!ft_strncmp(line + *i, "cd ", ft_strlen("cd ")))
		ft_cd(line + *i + ft_strlen("cd "));
	else if (!ft_strncmp(line + *i, "pwd ", ft_strlen("pwd ")) ||
		!ft_strncmp(line + *i, "pwd\n", ft_strlen("pwd\n")))
	{
		*i = *i + ft_strlen("pwd ");
		ft_printf("%s\n", ft_pwd());
	}
	else
		ft_printf("minishell: %s: command not found\n",
			ft_find_arg(line, i));
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
		if (!ft_strchr("$><;| \n\0", line[i]))
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
			ft_printf("whatever it received will be executed or printed etc.\n");
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
	//free(shell);
}
