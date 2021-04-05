/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_empty_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 19:10:49 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/05 13:59:19 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_empty_array(char *cmd)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 2);
	arr[0] = cmd;
	arr[1] = (char *) 0;
	return (arr);
}
