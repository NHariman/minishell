/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 14:38:58 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/05 15:47:31 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int		ft_pwd(void)
{
	long	size;
	char	*buf;
	char	*ptr;

	size = _PC_PATH_MAX;
	ptr = NULL;
	buf = (char *)malloc((size_t)size);
	if (buf)
		ptr = getcwd(buf, (size_t)size);
	printf("pwd result:\n%s\n_PC_PATH_MAX: %d\n", ptr, _PC_PATH_MAX);
	return (0);
}
