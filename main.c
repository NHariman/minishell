/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/06 03:55:24 by nhariman      ########   odam.nl         */
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

static void	minishell_parser(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strchr("eEpP", line[i]))
		line = ft_wordlow(line + i);
	if (!ft_strncmp(line + i, "echo ", ft_strlen("echo ")))
		ft_echo_parser(line + i + ft_strlen("echo "));
	else if (!ft_strncmp(line + i, "cd ", ft_strlen("cd ")))
		ft_cd(line + i + ft_strlen("cd "));
	else if (!ft_strncmp(line + i, "pwd ", ft_strlen("pwd ")) ||
		!ft_strncmp(line + i, "pwd\n", ft_strlen("pwd\n")))
		ft_pwd();
	else
		ft_printf("%s: command not found\n", ft_rm_endline(line));
}

int		main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = 0;
	i = 1;
	while (i == 1)
	{
		ft_printf("minishell> ");
		i = get_next_line(fd, &line);
		if (!ft_strncmp(line, "exit\n", ft_strlen("exit\n")))
			exit(0);
		minishell_parser(line); //function that processes the line argument.
		//free(line);
	}
	return (0);
}
