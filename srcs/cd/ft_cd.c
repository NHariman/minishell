/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:53 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/08 19:49:04 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** TO DO: multiple ../../..
** exchange strtrim for something that starts at the front
** and pays attention to " " and ' '
*/

static int	ft_cd_back(char *str)
{
	int		i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		i--;
		if (str[i] == '/')
			return (i);
	}
	return (-1);
}

static char	*ft_get_prevdir(void)
{
	char	*pwd;
	int		lastdir;
	char	*newdir;

	pwd = ft_pwd();
	lastdir = ft_cd_back(pwd);
	newdir = ft_substr(pwd, 0, lastdir);
	return (newdir);
}

void		ft_cd(char *str, int *i)
{
	char	*newdir;
	int		i;
	int		check;

	i = 0;
	errno = 0;
	while (str[i] == ' ')
		i++;
	if (!ft_strncmp(str + i, ".. ", ft_strlen(".. ")) ||
	!ft_strncmp(str + i, "..\n", ft_strlen("..\n")))
		newdir = ft_get_prevdir();
	else
		newdir = ft_strtrim(str, "\"\' \n");
	check = chdir(newdir);
	if (check == -1)
		ft_printf("minishell: cd: %s: %s\n",
			ft_rm_endline(str), strerror(errno));
	return ;
}
