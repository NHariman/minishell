/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:53 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/06 12:32:37 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_singlequotes_str(char *str, int *i)
{
	int		start;
	char	*new_str;

	*i = *i + 1;
	start = *i;
	while (str[*i] != '\'')
		*i = *i + 1;
	new_str = ft_substr(str, start, *i - start);
	*i = *i + 1;
	return (new_str);
}

static char	*ft_get_path(void)
{
	char	*newdir;

	newdir = NULL;
	if (g_shell.argv[1] == (char *) 0)
		newdir = ft_find_envvar("HOME");
	else
		newdir = ft_strdup(g_shell.argv[1]);
	return (newdir);
}

static void	ft_update_env_cd(char *olddirpath, char *newdirpath)
{
	char	*olddir;
	char	*newdir;

	olddir = ft_strjoin("OLDPWD=", olddirpath);
	newdir = ft_strjoin("PWD=", newdirpath);
	ft_update_env(olddir);
	ft_update_env(newdir);
	free(olddir);
	free(newdir);
}

void	ft_cd(void)
{
	char	*newdir;
	int		check;
	char	*olddir;

	olddir = ft_pwd();
	errno = 0;
	newdir = ft_get_path();
	check = chdir(newdir);
	free(newdir);
	if (check == -1)
	{
		ft_printf_err("minishell: cd: %s: %s\n",
			newdir, strerror(errno));
		g_shell.exit_code = 1;
	}
	else
	{
		newdir = ft_pwd();
		ft_update_env_cd(olddir, newdir);
		g_shell.exit_code = 0;
	}
	return ;
}
