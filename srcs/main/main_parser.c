/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:08:40 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/07 21:33:04 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_wordparser(char *line, int *i, t_shell *shell)
{
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
	else if (!ft_strncmp(line + *i, "export ", ft_strlen("export ")) ||
		!ft_strncmp(line + *i, "export\n", ft_strlen("export\n")))
		ft_printf("export function here\n");
	else
		ft_printf("minishell: %s: command not found\n",
			ft_find_arg(line + *i, i));
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

// static void	ft_find_cmd(char *line, int i, t_args *args)
// {
// 	int	start;
// 	int end;

// 	end = ft_strlen(line);
// 	while (line[i + start] != ' ')
// 		start++;
// 	args->cmd = ft_substr(line, i, i + start);
// 	args->str = ft_substr(line, start, end);
// 	free(line);
// }

static void	function_dispatcher(char *line, t_shell *shell)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		//ft_find_cmd(line, &i, args);
		if (ft_isalpha(line[i]))
			ft_wordparser(line, &i, shell);
		if (line[i] == '$')
			ft_printf("show env variable followed by: command not found lol.\n");
		else if (line[i] == '.')
			ft_printf("filename argument execute, execv()\n");
		else if (line[i] == '>')
			ft_printf("pipe function here, should handle > and >>, takes the shell struct\n");
		else if (line[i] == '<')
			ft_printf("pipe function here, should handle <, takes the shell struct\n");
		else if (line[i] == ';' || line[i] == '\n' || line[i] == '\0')
			ft_printf("line: %s\nwhatever it received will be executed or printed etc.\n", line + i);
		else if (line[i] == '|')
			ft_printf("pipe function here, |, takes the shell struct\n");
		i++;
	}
}

void		minishell_parser(char *line, char **envp)
{
	int			i;
	t_shell		*shell;
	t_args		*args;
	t_qts		qts;

	i = 0;
	shell = calloc(1, sizeof(t_shell));
	args = calloc(1, sizeof(t_args));
	shell->env = envp;
	ft_set_qts(&qts);
	ft_qt_line(line, &qts, &i);
	if (qts.dq % 2 != 0 || qts.sq % 2 != 0)
		ft_printf("Error\nHanging quotes. Echo failed.\n");
	else
		function_dispatcher(line, shell);
	//free(shell);
}
