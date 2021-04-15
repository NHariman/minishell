/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argv_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 11:34:47 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/15 18:08:29 by nhariman      ########   odam.nl         */
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

void	make_argv_rd(char *line)
{
	char	*new_line;
	int		i;
	char	*cmd;
	char	**tmp;

	g_shell.rds = ft_get_rdin(line);
	new_line = expand_envs(line);
	ft_printf("new_line = %s\n", new_line);
	i = 0;
	cmd = get_cmd(new_line, &i);
	tmp = ft_argv(new_line + i
			+ ft_iswhitespaces(new_line + i + 1));
	if (!tmp)
		g_shell.argv = ft_empty_array(cmd);
	else
	{
		g_shell.argv = ft_add_arr_front(tmp, cmd);
		ft_free_array(tmp, ft_arrlen(tmp));
	}
	i = 0;
	while (g_shell.argv[i] != NULL)
	{
		ft_printf("g_shell.argv[%i]: %s\n", i, g_shell.argv[i]);
		i++;
	}
	free(new_line);
}
