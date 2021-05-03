/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:53 by nhariman      #+#    #+#                 */
/*   Updated: 2021/05/03 14:08:17 by nhariman      ########   odam.nl         */
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
	if (ft_arrlen(g_shell.argv) == 1)
		newdir = ft_find_envvar("HOME");
	else if (g_shell.argv[1][0] == '-')
	{
		newdir = ft_find_envvar("OLDPWD");
		if (!newdir)
		{
			g_shell.exit_code = 1;
			ft_printf_err("minishell: cd: OLDPWD not set\n");
		}
		else
		{
			write(1, newdir, ft_strlen(newdir));
			write(1, "\n", 1);
		}
	}
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
	free(olddirpath);
	free(olddir);
	free(newdir);
}

static void	change_dir(char *newdir, char *olddir)
{
	int	check;

	check = chdir(newdir);
	if (check == -1)
	{
		free(olddir);
		ft_printf_err("minishell: cd: %s: %s\n",
			newdir, strerror(errno));
		free(newdir);
		g_shell.exit_code = 1;
	}
	else if (newdir)
	{
		free(newdir);
		newdir = ft_pwd();
		ft_update_env_cd(olddir, newdir);
	}
}

void	ft_cd(void)
{
	char	*newdir;
	char	*olddir;

	g_shell.exit_code = 0;
	olddir = ft_strdup_p(ft_pwd());
	if (olddir == NULL)
	{
		olddir = ft_find_envvar("PWD");
		if (olddir == NULL)
			olddir = ft_strdup("");
	}
	errno = 0;
	newdir = ft_get_path();
	if (!newdir)
	{
		free(olddir);
		return ;
	}
	change_dir(newdir, olddir);
	return ;
}
