/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cutstring_rd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:02:13 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 18:12:03 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void 		cut_string_shell_len(t_struct_rd *rd)
{
	while (rd->str[rd->len] != '\0' && rd->str[rd->len] != '\n' && rd->str[rd->len] != ' ' && rd->str[rd->len] != '>')
	{
		if (rd->str[rd->len] == '\\' && (rd->str[rd->len + 1] == '\''
		|| rd->str[rd->len + 1] == '\"' || rd->str[rd->len + 1] == '$'))
			rd->len += 2;
		else if (rd->str[rd->len] == '\"')
		{
			rd->len++;//moves away from double
			while (rd->str[rd->len] != '\"')//unitl its not
			{
				if (rd->str[rd->len] == '\\' && rd->str[rd->len + 1] == '\"')
					rd->len += 2;
				else
					rd->len++;
			}
			if (rd->str[rd->len] == '\"')
				rd->len++;
		}
		else if (rd->str[rd->len] == '\'')
		{
			rd->len++;//moves away from double
			while (rd->str[rd->len] != '\'')//unitl its not
			{
				if (rd->str[rd->len] == '\\' && rd->str[rd->len + 1] == '\'')
					rd->len += 2;
				else
					rd->len++;
			}
			if (rd->str[rd->len] == '\'')
				rd->len++;
		}
		else
			rd->len++;
	}
}

void		cut_string_shell(t_struct_rd *rd, t_shell *shell)
{
	int		i;
	int		len;
	t_struct_m	*echo;

	echo = ft_calloc(1, sizeof(t_struct_m));
	while (rd->str[rd->i] == ' ')
        rd->i++;
	i = 0;
	rd->len = rd->i;
	cut_string_shell_len(rd);
	len = rd->len - rd->i;
	rd->cache = (char *)malloc((len) * sizeof(char));
	while (rd->i < rd->len)
	{
		rd->cache[i] = rd->str[rd->i];
		i++;
		rd->i++;
	}
	rd->cache[i] = '\0';
	rd->i = rd->len;
	rd->file = ft_strdup(echo_main(rd->cache, echo, shell));
	free(echo->cache);
	free(echo->str);
	free(echo);
}

int         ft_len_string_rd(t_struct_rd *rd)
{
	int		len;

	len = 0;
	rd->i = rd->len;
	while (rd->str[rd->len] != '\0' && rd->str[rd->len] != '\n' && rd->str[rd->len] != '>')
	{
		rd->len++;
	}
	len = rd->len - rd->i;
	return(len);
}

void		ft_echo_string_rd(t_struct_rd *rd, t_shell *shell)
{
	char	*str;
	int		i;
	t_struct_m	*echo;

	echo = ft_calloc(1, sizeof(t_struct_m));

	i = 0;
	str = (char *)malloc((rd->len) * sizeof(char));
	while (rd->len >= 0)
	{
		str[i] = rd->str[rd->i];
		rd->i++;
		i++;
		rd->len--;
	}
	str[i] = '\0';
	rd->cache = ft_strdup(echo_main(str, echo, shell));
	free(str);
	free(echo->cache);
	free(echo->str);
	free(echo);
}