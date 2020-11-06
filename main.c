/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/06 23:26:38 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

/*
** TODO:
** open stdin and read from it. (GNL)
*/

static char	*ft_wordlow(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isalpha(line[i]))
			break ;
		line[i] = ft_tolower(line[i]);
		i++;
	}
	return (line);
}

/*
** TODO: find word and create string until the end or if it finds a
** >> > < | ;
** create the line BEFORE you send it to the main function.
** so you can also create command not found accurately.
*/

static void	ft_wordparser(char *line, int *i, t_shell *shell)
{
	if (ft_strchr("eEpP", line[*i]))
		line = ft_wordlow(line + *i);
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

static void	minishell_parser(char *line, char **envp)
{
	int			i;
	t_shell		*shell;

	i = 0;
	shell = calloc(1, sizeof(t_shell));
	shell->env = envp;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (ft_isalpha(line[i]))
			ft_wordparser(line, &i, shell);
		else if (line[i] == '$')
			ft_printf("show env variable followed by: command not found lol.\n");
		else if (line[i] == '>')
			ft_printf("pipe function here, should handle > and >>, takes the shell struct\n");
		else if (line[i] == '<')
			ft_printf("pipe function here, should handle <, takes the shell struct\n");
		else if (line[i] == ';')
			ft_printf("whatever it received will be executed or printed etc.\n");
		else if (line[i] == '|')
			ft_printf("pipe function here, |, takes the shell struct\n");
		i++;
	}
	free(shell);
}

int		main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	*line;
	char	**hold;

	i = argc;
	hold = argv;
	while (i > 0)
	{
		ft_printf("minishell> ");
		i = get_next_line(0, &line);
		if (!ft_strncmp(line, "exit\n", ft_strlen("exit\n")))
			exit(0);
		minishell_parser(line, envp);
		free(line);
	}
	return (0);
}
