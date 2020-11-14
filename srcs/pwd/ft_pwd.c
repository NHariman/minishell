/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:58 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/14 19:59:11 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_pwd(void)
{
	char	cwd[1024];
	char	*cwd_res;
	char	*ret;

	cwd_res = getcwd(cwd, sizeof(cwd));
	errno = 0;
	if (cwd_res == NULL)
	{
		ft_printf("Error\n%s\n", strerror(errno));
		return (NULL);
	}
	ret = ft_strdup(cwd);
	return (ret);
}

char		*ft_pwd_main(char *str, int *i)
{
	char	cwd[1024];
	char	*cwd_res;
	char	*ret;

	cwd_res = getcwd(cwd, sizeof(cwd));
	errno = 0;
	if (cwd_res == NULL)
	{
		ft_printf("Error\n%s\n", strerror(errno));
		return (NULL);
	}
	ret = ft_strdup(cwd);
	while (!ft_strchr("><|;\n", str[*i]))
		*i = *i + 1;
	return (ret);
}
