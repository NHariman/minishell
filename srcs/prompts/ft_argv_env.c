/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argv_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 11:34:47 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/22 23:50:49 by nhariman      ########   odam.nl         */
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
		else if (line[i] == '$' && !ft_strchr(" ;\n", line[i + 1])
			&& line[i + 1] != '\0')
			ft_parse_dollar(line, &i, trim);
		else
			i++;
	}
}

static char	*expand_envs(char *line)
{
	t_trim	trim;
	char	*output;
	char	*rdless;

	trim.start = 0;
	trim.res = (char *) 0;
	rdless = trim_rd(line);
	make_new_str(rdless, &trim);
	if (trim.res)
	{
		stitch_end(rdless, &trim, ft_strlen(rdless));
		output = ft_strdup(trim.res);
		free(trim.res);
	}
	else
		output = ft_strdup(rdless);
	free(rdless);
	return (output);
}

static int	get_argv(char *new_line)
{
	char	*cmd;
	char	**tmp;
	int		i;

	i = 0;
	cmd = get_cmd(new_line, &i);
	if (ft_strchr(cmd, '=') != NULL)
	{
		free(new_line);
		return (free_and_return(cmd, 1));
	}
	tmp = ft_argv(new_line + i
			+ ft_iswhitespaces(new_line + i + 1));
	if (!tmp)
		g_shell.argv = ft_empty_array(cmd);
	else
	{
		g_shell.argv = ft_add_arr_front(tmp, cmd);
		ft_free_array(tmp, ft_arrlen(tmp));
	}
	return (0);
}

int	make_argv_rd(char *line, int *new_fds)
{
	char	*new_line;

	g_shell.rds = ft_get_rdin(line);
	if (g_shell.rds)
	{
		if (rd_main(g_shell.rds, new_fds))
		{
			g_shell.argv = NULL;
			return (1);
		}
		g_shell.new_fds[IN] = new_fds[IN];
		g_shell.new_fds[OUT] = new_fds[OUT];
	}
	new_line = expand_envs(line);
	if (new_line[0] == '\0')
		return (free_and_return(new_line, 1));
	if (get_argv(new_line))
		return (free_and_return(new_line, 1));
	free(new_line);
	return (0);
}
