/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/29 16:05:38 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
file,rd,file,rd,file,rd;;string
hello too many ' '
*/

void			ft_file_input_string(t_struct_rd *rd, t_shell *shell)
{
	t_struct_m	*echo;

	echo = ft_calloc(1, sizeof(t_struct_m));
	rd->tmp = ft_strdup(echo_main(rd->string, echo, shell));
	rd->string = ft_strdup(ft_strtrim(rd->tmp, "\n"));
	free(rd->tmp);
	free(echo->tmp);
	free(echo->str);
	free(echo);
	rd->cache = ft_strjoin(rd->output, "\n");
	free(rd->output);
	rd->output = ft_strjoin(rd->cache, rd->string);
	rd->string_save = ft_strdup(rd->output);
	free(rd->cache);
	free(rd->string);
}

int				rd_loop(t_struct_rd *rd, t_shell *shell)
{
	int			error;
	t_struct_m	*echo;

	echo = ft_calloc(1, sizeof(t_struct_m));
	rd->i = 0;
	rd->file = ft_strdup("");
	while (rd->str[rd->i] && rd->str[rd->i] != '\n' && error == 0)
	{
		set_value_rd(rd);
		error = rd_check_error_rd(rd);
		if (error != 0)
			return (error);
		ft_get_file(rd, shell);
		ft_printf("input file == [%s]\n", rd->file);//have the file right here
		while (rd->str[rd->i] == ' ')
			rd->i++;
		//make sure you stand after the file on the next chaarcter
		//that should be > or >> or < or end of line/]n
	}
	// fill in the nb 3 and nb1/2 if open
	return (error);
}
