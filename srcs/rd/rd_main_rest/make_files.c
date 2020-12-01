/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_files.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 19:23:37 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/28 15:44:55 by ybakker       ########   odam.nl         */
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

	fd = 0;
	errno = 0;
	if (shell->fd != -1 && nb != 3)
	{
		close(shell->fd);
	}
	ft_printf("open closee [%s]\n", str);
	if (nb == 3)
	{
		fd = open(str, O_RDWR);
		redirect_file(fd, shell);
		close(fd);
		return (0);
	}
	else
		shell->fd = open(str, O_RDWR | O_CREAT, 0666);
	if (shell->fd < 0)
	{
		ft_printf_err("Error\n%s\n", strerror(errno));
		shell->exit_code = 1;
		return (1);
	}
	shell->oldnb = nb;
	nb = 0;
	return (0);
}

void	ft_rd_output(char *str, t_shell *shell)
{
	int		i;
	int		nb;
	char	*file;
	char	*string;

	i = 0;
	while (str[i])
	{
		while (str[i] == '\n')
			i++;
		file = ft_strcpystr(i, str, '\n');
		while (str[i] != '\n')
			i++;
		i++;
		nb = ft_c_atot(str[i]);//get dir
		i++;
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			i += 2;
			string = ft_strcpystr(i, str, '\0');
			open_fill_close_file(file, string, nb, shell);
			free(file);
			free(string);
			return ;
		}
		else
		{
			if (open_close_file(file, nb, shell) == 1)
			{
				free(file);
				return ;
			}
			i++;
		}
		free(file);
	}
	close(shell->fd);
}
