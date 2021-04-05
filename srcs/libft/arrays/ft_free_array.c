/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 18:39:28 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/05 13:58:31 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_array(char **arr, int len)
{
	int	i;

	i = 0;
	if (!arr || arr[0] == (char *) 0)
		return ;
	while (i < len)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
	arr = NULL;
}
