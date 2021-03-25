/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 23:38:16 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/25 18:55:41 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** receives the string past the echo, need to trim away pipe functions.
** example:
** -n string "string < dsthdf" 'dfdkfhaf >'  > file
** should send everything until              ^ this character.
** test string, good: echo "test >" '<'       "test | " < test
** test string, bad: echo "test >" '<       "test | " < test
*/

static int	ft_isflag(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_skip_flags(char **arr, int *check)
{
	int	i;

	i = 1;
	while (arr[i] != (char *) 0)
	{
		if (!ft_isflag(arr[i]))
			return (i);
		*check = 1;
		i++;
	}
	return (i);
}

static char	*ft_make_echo_str(char **argv, int i)
{
	char	*tmp;
	char	*echo_str;
	char	*newstr;

	tmp = ft_strdup(argv[i]);
	while (argv[i + 1] != (char *) 0)
	{
		newstr = ft_charjoin(tmp, ' ');
		free(tmp);
		echo_str = gnl_strjoin(newstr, argv[i + 1]);
		tmp = echo_str;
		i++;
	}
	return (tmp);
}

void	ft_echo(void)
{
	int		i;
	int		check;
	char	*tmp;

	i = 0;
	check = 0;
	if (ft_arrlen(g_shell.argv) == 1)
		tmp = NULL;
	else
	{
		i = ft_skip_flags(g_shell.argv, &check);
		if (g_shell.argv[i] == (char *) 0)
			tmp = ft_strdup("");
		else
			tmp = ft_make_echo_str(g_shell.argv, i);
	}
	if (check == 1)
		ft_printf("%s", tmp);
	else
		ft_printf("%s\n", tmp);
	free(tmp);
	g_shell.exit_code = 0;
	return ;
}
