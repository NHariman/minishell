/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 21:41:05 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/05 14:00:05 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_empty_array(char *cmd)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 2);
	arr[0] = cmd;
	arr[1] = (char *) 0;
	return (arr);
}
