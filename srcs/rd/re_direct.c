/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 16:17:01 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
	first check for >

	if file is there, chck if its ther,e then jsut put the info in there
	//if file is not there, create and then ut it in

	go to the back until you see a > if there is a " " then put that on and move
	until you see another one that hasn't gotten a /, if you find a , that doens't have double or
	single on, then you can save this as the rdi->i and use begin, and then the first string
	you get until empty line or '\0' is the file name, if there is no '0'then the rest is a string you put in
	str. now you move along the logic

	frist string is file
	second string is word until <
	save this string and put it through the funnel
	keep saving the tring accordingly
	> means after eah other
	>> means add a \n and then the word

	>> means you add the whole str that is created, fi ther eis already one, then do it under

	echo hello  >> file1 pwd >> file2 hello >>file3
	if echo, then the str are str
	else, for example pwd, you only hav the input pwd

	action txt > file txt
*/

int			rd_loop(t_struct_rd *rd, t_shell *shell)
{

}

int		start_rd(t_struct_rd *rd, t_shell *shell)
{
	char	*str;
	int		error;

	rd->i = 0;
	error = 0;
	cut_string_shell(rd->s_str, rd, shell);
	while (rd->str[rd->i] == ' ')
		rd->i++;
	else if (error == 0)
		error = rd_loop(rd, shell);
	return (error);
}

int		*rd_main(char *str, t_shell *shell)
{
    t_struct_rd	*rd;
	int		error;

    rd = calloc(1, sizeof(t_struct_m));
	set_value_rd(rd);
	rd->s_str = ft_strdup(str);
	free(str);
	error = start_rd(rd, shell);
    free(rd);
	return (error);
}
