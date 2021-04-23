/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 18:37:13 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/23 22:38:35 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr || arr[0] == (char *) 0)
		return (-1);
	while (arr[i] != (char *) 0)
		i++;
	return (i);
}
