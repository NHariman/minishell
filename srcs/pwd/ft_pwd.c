/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:58 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/05 18:37:51 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

char		*ft_pwd(void)
{
	char	cwd[1024];
	char	*cwd_res;
	char	*ret;

	cwd_res = getcwd(cwd, sizeof(cwd));
	if (cwd_res == NULL)
	{
		perror("getcwd() error");
		return (NULL);
	}
	ft_printf("cwd: %s\n", cwd);
	ret = ft_strdup(cwd);
	return (ret);
}
