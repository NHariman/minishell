/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_files.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 12:14:19 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 14:42:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static	void	rd_file_free(t_struct_rd *rd, t_struct_m *echo)
{
	rd->tmp = ft_strtrim(rd->cache, "\n");
	free(rd->cache);
	rd->cache = ft_strdup(echo_main(rd->tmp, echo));
	free(echo->str);
	if (rd->file)
		free(rd->file);
	rd->file = ft_strtrim(rd->cache, "\n");
	free(rd->cache);
	free(echo->tmp);
}

void	rd_get_file(t_struct_rd *rd, t_struct_m *echo)
{
	int	i;
	int	len;
	int	start;

	i = 0;
	start = rd->i;
	while (rd->str[rd->i] != '\n' && rd->str[rd->i] != '\0'
		&& rd->str[rd->i] != '<' && rd->str[rd->i] != '>')
		rd->i++;
	len = rd->i - start;
	rd->i = start;
	rd->cache = (char *)malloc(len * sizeof(char));
	while (len > 0)
	{
		rd->cache[i] = rd->str[rd->i];
		i++;
		rd->i++;
		len--;
	}
	rd->cache[i] = '\0';
	rd_file_free(rd, echo);
	free(echo->cache);
}

