<<<<<<< Updated upstream
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:53 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/17 20:03:49 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_singlequotes_str(char *str, int *i)
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

static char	*ft_get_path(char *str, int *i, t_shell *shell)
{
	char	*newdir;

	newdir = NULL;
	if (str[*i] == '\n')
		newdir = ft_find_envvar("HOME", shell);
	else
		newdir = ft_no_quotes_str(str, i, shell);
	return (newdir);
}

static void	ft_update_env(t_shell *shell, char *olddir, char *newdir)
{
	char	*olddir_input;
	char	*newdir_input;
	int		i;

	olddir_input = ft_strjoin("OLDPWD=", olddir);
	newdir_input = ft_strjoin("PWD=", newdir);
	i = 0;
	if (!ft_find_envvar("OLDPWD", shell))
		ft_add_env_back(shell, olddir);
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], "OLDPWD=", ft_strlen("OLDPWD=")))
			shell->env[i] = ft_strdup(olddir_input);
		else if (!ft_strncmp(shell->env[i], "PWD=", ft_strlen("PWD=")))
			shell->env[i] = ft_strdup(newdir_input);
		i++;
	}
	free(olddir_input);
	free(newdir_input);
}

void		ft_cd(char *str, int *i, t_shell *shell)
{
	char	*newdir;
	int		check;
	char	*olddir;

	olddir = ft_pwd();
	errno = 0;
	while (str[*i] == ' ')
		*i = *i + 1;
	newdir = ft_get_path(str, i, shell);
	check = chdir(newdir);
	if (check == -1)
	{
		ft_printf_err("minishell: cd: %s: %s\n",
			newdir, strerror(errno));
		shell->exit_code = 1;
	}
	else
		ft_update_env(shell, olddir, ft_pwd());
	return ;
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:53 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/15 18:05:06 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_singlequotes_str(char *str, int *i)
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

static char	*ft_get_path(char *str, int *i, t_shell *shell)
{
	char	*newdir;

	newdir = NULL;
	if (str[*i] == '\n')
		newdir = ft_find_envvar("HOME", shell);
	else
		newdir = ft_no_quotes_str(str, i, shell);
	return (newdir);
}

static void	ft_update_env(t_shell *shell, char *olddir, char *newdir)
{
	char	*olddir_input;
	char	*newdir_input;
	int		i;

	olddir_input = ft_strjoin("OLDPWD=", olddir);
	newdir_input = ft_strjoin("PWD=", newdir);
	i = 0;
	if (!ft_find_envvar("OLDPWD", shell))
		ft_add_env_back(shell, olddir);
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], "OLDPWD=", ft_strlen("OLDPWD=")))
			shell->env[i] = ft_strdup(olddir_input);
		else if (!ft_strncmp(shell->env[i], "PWD=", ft_strlen("PWD=")))
			shell->env[i] = ft_strdup(newdir_input);
		i++;
	}
	free(olddir_input);
	free(newdir_input);
}

void		ft_cd(char *str, int *i, t_shell *shell)
{
	char	*newdir;
	int		check;
	char	*olddir;

	olddir = ft_pwd();
	errno = 0;
	while (str[*i] == ' ')
		*i = *i + 1;
	newdir = ft_get_path(str, i, shell);
	check = chdir(newdir);
	if (check == -1)
		ft_printf_err("minishell: cd: %s: %s\n",
			newdir, strerror(errno));
	else
		ft_update_env(shell, olddir, ft_pwd());
	shell->check.cd = 1;
	return ;
}
>>>>>>> Stashed changes
