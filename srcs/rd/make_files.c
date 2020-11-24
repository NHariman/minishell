/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_files.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 19:23:37 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/21 21:41:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>
//what happened if you go back and make a file in someone elses folder on Codam, what happens?
//echo "hi" > /exam/file1

static int		ft_c_atot(char c)
{
	char	*str;
	int		nb;

	str = (char *)malloc((2) * sizeof(char));
	str[0] = c;
	str[1] = '\0';
	nb = ft_atoi(str);
	return (nb);
}

static int		open_close_file(char *str, int nb, t_shell *shell)
{
	int		fd;

	errno = 0;
	ft_printf("open closee\n");
	fd = open(str, O_EXCL | O_CREAT, 0666);
	if (fd < 0)
	{
		ft_printf_err("Error\n%s\n", strerror(errno));
		shell->exit_code = 1;
		return (1);
	}
	close(fd);
	nb = 0;
	return (0);
}

static int		open_fill_close_file(char *str, int nb, t_shell *shell)
{
	int		fd;

	errno = 0;
	ft_printf("fill file close\n");
	fd = open(str, O_WRONLY | O_APPEND, 0666);
	if (fd < 0)
	{
		ft_printf_err("Error\n%s\n", strerror(errno));
		shell->exit_code = 1;
		return (1);
	}
	if (nb == 1)
	{
		write(fd, "helllllllo\n", 5);
		return (0);
	}
	if (nb == 2)
	{
		write(fd, "niks is hier\n", 5);
		return (0);
	}
	nb = 0;
	// if (shell->check.shell == 1)
	// {
	// 	dup2(fd, 255);
	//	dup(fd, 1);
	// 	//shell;
	// 	close(fd);
	// }
	close(fd);//if shell is on, do this after shell is done
	return (0);
}

void	ft_rd_output(char *str, t_shell *shell)
{
	int		i;
	int		nb;
	char	*string;

	ft_printf("string str output == : {%s}\n", str);
	i = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		string = ft_strcpystr(i, str, '\n');
		while (str[i] != '\n')
			i++;
		nb = ft_c_atot(str[i]);//get dir
		i += 2;
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			if(open_fill_close_file(string, nb, shell) == 1)
			{
				free(string);
				return ;
			}
			free(string);
			return ;
		}
		else
		{
			if (open_close_file(string, nb, shell) == 1)
			{
				free(string);
				return ;
			}
			i++;
		}
		free(string);
	}
}
