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
	int i;

	i = 0;
	echo->t_begin = 0;
	echo->t_split = 0;
	echo->t_cache = NULL;
	echo->t_tmp = NULL;
	while (echo->str[i] || echo->str[i] != '\n')
	{
		if (echo->str[i] == '$')
		{
			echo->t_split = i;
			ft_split_begin(echo);
			echo->t_tmp = ft_variable(echo);
			echo->t_cache = ft_strjoin(echo->t_cache, echo->t_tmp);
			free(echo->t_tmp);
			ft_split_end(echo);
			echo->str = ft_strjoin(echo->t_cache, echo->t_tmp);
			free(echo->t_cache);
			free(echo->t_tmp);
		}
		i++;
	}
}

void   ft_split_begin(t_struct_m *echo)
{
	//split is the len
	int	i;

	i = 0;
	echo->cache = (char *)malloc((echo->t_split + 1) * sizeof(char));
	if (!echo->cache)
		return ;
	ft_fillstr(echo->cache, '0', echo->t_split);
	while (echo->cache[i])
	{
		echo->cache[i] = echo->str[i];
		i++;
	}
}

char*	ft_variable(t_struct_m *echo)
{
	// ft_search_variable(echo);
	//for now its path
	char	cwd[1024];
	char	*cwd_res;
	char	*ret;
	int 	i;

	cwd_res = getcwd(cwd, sizeof(cwd));
	if (cwd_res == NULL)
	{
		perror("getcwd() error");
		return (NULL);
	}
	ret = ft_strdup(cwd);
	i = strlen(ft_strdup("PATH"));
	echo->t_split = echo->t_split + i;//now its at the end of the variable
	return (ret);
}

void   ft_split_end(t_struct_m *echo)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(echo->str);
	echo->t_tmp = (char *)malloc((len - echo->t_split + 1) * sizeof(char));
	if (!echo->t_tmp)
		return ;
	ft_fillstr(echo->t_tmp, '0', len - echo->t_split);
	while (echo->t_tmp[i])
	{
		echo->t_tmp[i] = echo->str[echo->t_split];
		echo->t_split++;
		i++;
	}
}
