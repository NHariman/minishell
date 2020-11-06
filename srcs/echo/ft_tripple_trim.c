/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tripple_trim.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 21:12:40 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/05 22:35:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

void   ft_tripple_trim(t_struct_m *echo)
{
	echo->t_begin = 0;
	echo->t_split = 0;
	while (echo->str[echo->t_split] && echo->str[echo->t_split] != '\n')
	{
		if (echo->str[echo->t_split] == '$')
		{
			ft_split_begin(echo);
			ft_variable(echo);
			echo->t_cache = ft_strjoin(echo->t_cache, echo->t_tmp);
			free(echo->t_tmp);
			ft_split_end(echo);
			free(echo->str);
			echo->str = ft_strjoin(echo->t_cache, echo->t_tmp);
			free(echo->t_tmp);
			free(echo->t_cache);
			echo->t_split = 0;
		}
		else
		{
			echo->t_split++;
		}
	}
	//remove the empty lines at the end of the string
}

void	ft_variable(t_struct_m *echo)
{
	int 	len;
	int		start;
	char*	str;
	int		error = -1;

	len = 0;
	start = echo->t_split;
	while (echo->str[echo->t_split] && echo->str[echo->t_split]
			!= '\n' && echo->str[echo->t_split] != ' ')
	{
		len++;
		echo->t_split++;	
	}
	str = ft_substr(echo->str, start, len);
	ft_printf("str = [%s]\n", str);
	ft_search_variable(echo, str, start);
	free(str);
	if (error == -1)
	{
		free(echo->t_tmp);
		echo->t_tmp = ft_strdup("");
	}
}

void   ft_split_begin(t_struct_m *echo)
{
	//split is the len
	int	i;

	i = 0;
	echo->t_cache = (char *)malloc((echo->t_split + 1) * sizeof(char));
	if (!echo->t_cache)
		return ;
	ft_fillstr(echo->t_cache, '0', echo->t_split);
	while (echo->t_cache[i])
	{
		echo->t_cache[i] = echo->str[i];
		i++;
	}
}

void   ft_split_end(t_struct_m *echo)
{
	int	i;
	int	len;
	int	split;

	i = 0;
	split = echo->t_split;
	len = ft_strlen(echo->str);
	echo->t_tmp = (char *)malloc((len - split + 1) * sizeof(char));
	if (!echo->t_tmp)
		return ;
	ft_fillstr(echo->t_tmp, '0', len - split);
	while (echo->t_tmp[i])
	{
		echo->t_tmp[i] = echo->str[split];
		split++;
		i++;
	}
	echo->t_tmp[i] = '\0';
}
