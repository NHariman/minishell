<<<<<<< Updated upstream
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/18 12:13:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

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
		ft_printf("\033[1;36m");
		ft_printf("minishell> ");
		ft_printf("\033[0m");
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
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 19:10:50 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

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
		ft_printf("\033[1;36m");
		ft_printf("minishell> ");
		ft_printf("\033[0m");
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
>>>>>>> Stashed changes
