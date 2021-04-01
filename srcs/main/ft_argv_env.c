/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argv_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 11:34:47 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/01 14:59:55 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	stitch_end(char *line, t_trim *trim, int i)
{
	char	*str_end;
	char	*tmp;

	str_end = ft_substr(line, trim->start, i - trim->start);
	tmp = gnl_strjoin(trim->res, str_end);
	trim->res = ft_strdup(tmp);
	free(tmp);
	free(str_end);
}

static void	make_new_str(char *line, t_trim *trim)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr("\'\"", line[i])
			&& ft_backslash_check(line, i) % 2 == 0)
			ft_skip_quotes(line, &i, line[i]);
		if (line[i] == '$' && !ft_strchr(" ;\n", line[i + 1])
			&& line[i + 1] != '\0')
			ft_parse_dollar(line, &i, trim);
		i++;
	}
}

static char	*expand_envs(char *line)
{
	t_trim	trim;
	char	*output;

	trim.start = 0;
	trim.res = (char *) 0;
	make_new_str(line, &trim);
	if (trim.res)
	{
		stitch_end(line, &trim, ft_strlen(line));
		output = ft_strdup(trim.res);
		free(trim.res);
	}
	else
		output = ft_strdup(line);
	return (output);
}

void	make_argv_rd(char *line)
{
	char	*new_line;
	int		i;
	char	*cmd;
	char	**tmp;

	new_line = expand_envs(line);
	i = 0;
	cmd = get_cmd(new_line, &i);
	tmp = ft_argv(new_line + i
			+ ft_iswhitespaces(new_line + i + 1));
	if (!tmp)
		g_shell.argv = empty_array(cmd);
	else
		g_shell.argv = ft_add_arr_front(tmp, cmd);
	g_shell.rds = ft_get_rdin(new_line);
	free(new_line);
}
