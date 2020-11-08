/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo_no_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 15:07:00 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/08 16:41:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

void	ft_check_back_no(char *str, int i, t_struct_q *han)
{
	i--;
	if (str[i] == ' ' && han->end != 1)
		han->begin++;
	if (han->end == 1)
		han->end = 0;
}

void	ft_check_end_no(char *str, int i, t_struct_q *han)
{
	i++;
	if (str[i] == ' ')
	{
		i = skip_character(str, i, ' ');
		if (str[i] != '\0' && str[i] != '\n')
			han->end = 1;
	}
}

void	echo_no_str(t_struct_q *han)
{
    han->i = skip_character(han->s_str, han->i, ' ');
	ft_check_back_no(han->s_str, han->i, han);
	han->len = 0;
	while (han->s_str[han->i] != '\0' && han->s_str[han->i] != '\n' && han->s_str[han->i] != ' ' && han->s_str[han->i] != '\"' && han->s_str[han->i] != '\'')
    {
        han->len++;
        han->i++;
    }
	ft_check_end_no(han->s_str, han->i, han);
	han->s_cache = (char *)malloc((han->len + 1) * sizeof(char));
	if (han->s_cache == NULL)
		han->error = -1;
	else
	{
		han->y = 0;
		han->i = han->i - han->len;
		while (han->y < han->len)
		{
			han->s_cache[han->y] = han->s_str[han->i];
			han->y++;
			han->i++;
		}
		han->s_cache[han->y] = '\0';
		if (han->begin == 1)
		{
			han->s_tmp = ft_strjoin(" ", han->s_cache);
			free(han->s_cache);
			han->s_cache = ft_strdup(han->s_tmp);
			free(han->s_tmp);
		}
		if (han->end == 1)
		{
			han->s_tmp = ft_strjoin(han->s_cache, " ");
			free(han->s_cache);
			han->s_cache = ft_strdup(han->s_tmp);
			free(han->s_tmp);
		}
	}
    han->begin = 0;
	han->s_tmp = ft_strjoin(han->s_store, han->s_cache);
	free(han->s_store);
	free(han->s_cache);
	han->s_store = ft_strdup(han->s_tmp);//cache to put in str later
    han->i = skip_character(han->s_str, han->i, ' ');
}
