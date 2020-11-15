/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cutstring_rd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:02:13 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 12:29:16 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void		*cut_string_shell_len(char *str, t_struct_rd *rd)
{
	while (rd->doubble == 0 && rd->single == 0 && (str[rd->len] != ' ' || str[rd->len] != '>'))
	{
		if (str[rd->len] == '\\' && single == 0 && (str[i + 1] == '\''
		|| str[i + 1] == '\"' || str[i + 1] == '$'))
			rd->len += 2;
		else if (str[rd->len] == '\\' && str[i + 1] == '\\')
			rd->len += 2;
		else if (str[rd->len] == '$' && single == 0)
		{
			rd->error = -1;
			return (NULL);
		}
		else if (str[rd->len] == '\"')
		{
			if (rd->doubble == 0 && rd->single == 0)
				rd->doubble = 1;
			else if (rd->doubble == 1 && rd->single == 0)
				rd->doubble = 0;
            rd->len++;
		}
		else if (str[rd->len] == '\'')
		{
			if (rd->single == 0 && rd->doubble == 0)
				rd->single = 1;
			else if (rd->single == 1 && rd->doubble == 0)
				rd->single = 0;
            rd->len++;
		}
		else
			rd->len++;
	}
}

char			*cut_string_shell(char *str, t_struct_rd *rd)
{
	int		i;

	i = 0;
	while (str[rd->i] == ' ')
		rd->i++;
	rd->len = rd->i;
	cut_string_shell_len(str, rd);
	rd->string = (char *)malloc((rd->len + 1) * sizeof(char));
	while (rd->i <= rd->len)
	{
		rd->string[i] = str[rd->i];
		i++;
		rd->i++;
	}
	rd->string[i] = '\0'
	return (str);
}