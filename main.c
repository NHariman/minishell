/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 18:53:14 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

/*
** TODO:
** open stdin and read from it. (GNL)
*/

static void	minishell_parser(char *line)
{
	int i;

	i = 0;
	ft_printf("%s\n", line);
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(line, "echo ", ft_strlen("echo ")))
			exit(0); // replace with echo function

}

static char	*ft_strlower(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = ft_tolower(line[i]);
		i++;
	}
	return (line);
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
		i = get_next_line(fd, &line);
		line = ft_strlower(line);
		if (!ft_strncmp(line, "exit\n", ft_strlen("exit\n")))
			exit(0); // replace with an exit command that frees everything.
		minishell_parser(line); //function that processes the line argument.
		//free(line);
	}
	return (0);
}
