/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/12 15:29:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

// int		main(int argc, char *argv[], char *envp[])
// {
// 	int		i;
// 	char	*line;
// 	char	**hold;

// 	i = argc;
// 	hold = argv;
// 	while (i > 0)
// 	{
// 		ft_printf("minishell> ");
// 		i = get_next_line(0, &line);
// 		if (!ft_strncmp(line, "exit\n", ft_strlen("exit\n")))
// 			exit_minishell();
// 		minishell_parser(line, envp);
// 		free(line);
// 	}
// 	return (0);
// }

int		main(int argc, char *argv[], char *envp[])
{
	int			i;
	char		*line;
	char		**hold;
	char		*str;
	t_shell		*shell;
	// t_struct_m	*echo;
	t_struct_rd	*rd;

	i = argc;
	hold = argv;
	shell = calloc(1, sizeof(t_shell));
	rd = calloc(1, sizeof(t_struct_m));
	shell->env = envp;
	while (i > 0)
	{
		ft_printf("minishell> ");
		i = get_next_line(0, &line);
		if (!ft_strncmp(line, "exit\n", ft_strlen("exit\n")))
			exit(0);
		str = rd_main(line, rd, shell);
		//minishell_parser(line, envp);
		// free(line);//double free???
		free(str);
	}
	return (0);
}
