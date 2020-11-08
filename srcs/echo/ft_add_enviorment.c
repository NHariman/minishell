/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_enviorment.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 18:42:42 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/08 22:28:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void   ft_split_begin(t_struct_tr *trim)
{
	printf("c == [%c] i == [%i]\n", trim->s_str, trim->begin);
	
}

static void   ft_split_end(t_struct_tr *trim)
{
	printf("c == [%c] i == [%i]\n", trim->s_str, trim->begin);
}

int		ft_split_variable(t_struct_tr *trim)
{
	printf("c == [%c] i == [%i]\n", trim->s_str, trim->begin);
	int		i;

	i = trim.begin;
	i--;
	if (trim->s_str[trim->begin] == '\\')
	{
		ft_split_begin(trim);
		ft_split_end(trim);
		free(trim->s_str);
		trim->s_str = ft_strjoin(trim->s_begin, trim->s_end);
		free(trim->s_begin);
		free(trim->s_end);
		printf("c == [%c] i == [%i]\n", trim->s_str, trim->begin);
		return (1);
	}
	return (0);
}

/*
----variablles---
if in $ and single is on, then sue this logic, you don't do the variable
if uneven, add 1 and divide by 2. the result is the amount of backslashes
example. if there are 5%2 = 1, so uneven, so 5 + 1 1 = 6. 6/2 == 3. so 3 backslashes

if money is in double


----quotations---
if no quotation or double. use the specil format 
if 1 then no variable but no backslash added either
if uneven, then 01122334455 pattern no variable
if even 00112233 with \/ after itadd variable

//also works with double quotations
if they're even the the quoatation after it isn't stopped, hwoever, the amount is divided by 2 and thats the amount
if its uneven, 'no logic yet"
*/
void    ft_add_variables(t_struct_m *echo, t_shell *shell)
{
	t_struct_tr trim;

	set_value_trim(&trim);
	trim.s_str = ft_strdup(echo->str);
	free(echo->str);
	while (trim.s_str[trim.begin] && trim.s_str[trim.begin] != '\n')
	{
		if (trim.s_str[trim.begin] == '$')
		{
			
		}
		trim.begin++;
	}
	echo->str = ft_strdup(trim.s_str);
	free(trim.s_str);
}
