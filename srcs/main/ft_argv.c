/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argv.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 19:01:09 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/08 18:20:26 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_skip_through(char *str, int *i)
{
	while ((str[*i] != ' ' && str[*i] != '\0'))
	{
		if (ft_strchr("\'\"", str[*i]) && ft_backslash_check(str, *i) % 2 == 0)
			ft_skip_quotes(str, i, str[*i]);
		else if (str[*i] == '\\' && ft_strchr(" \\\'\"", str[*i + 1]))
			*i = *i + 2;
		else
			*i = *i + 1;
	}
}

int	ft_count_arr(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr("<>", str[i]) && ft_backslash_check(str, i) % 2 == 0)
			ft_skip_rd(str, &i);
		else if (str[i] != ' ')
		{
			ft_skip_through(str, &i);
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_make_array(char **arr, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && count < g_shell.argc)
	{
		if (str[i] != ' ')
		{
			if (str[i] == '<' || str[i] == '>')
				ft_skip_rd(str, &i);
			if (str[i] == '\0')
				break ;
			arr[count] = ft_no_quotes_str(str, &i, " <>");
			if (!arr[count])
				return (NULL);
			count++;
		}
		else
			i++;
	}
	arr[count] = (char *) 0;
	return (arr);
}

char	**ft_argv(char *s)
{
	char	**split;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	g_shell.argc = ft_count_arr(s);
	if (g_shell.argc == 0)
		return (NULL);
	split = (char **)malloc((g_shell.argc + 2) * sizeof(char *));
	if (!split)
		ft_malloc_fail("ft_argv, split malloc");
	split = ft_make_array(split, s);
	if (!split)
		ft_malloc_fail("ft_argv, split, ft_make_array");
	return (split);
}
