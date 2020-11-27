/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_quotations_parser.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 13:44:13 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/27 07:22:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*ft_insert_nqt_output(char *str, int i, t_trim *trim)
{
	char		*output;
	char		*old_str;

	output = NULL;
	old_str = NULL;
	if (trim->res == NULL)
		output = ft_substr(str, trim->start, i - trim->start);
	else
	{
		old_str = trim->res;
		output = gnl_strjoin(old_str,
			ft_substr(str, trim->start, i - trim->start));
	}
	return (output);
}

static	void	ft_nqts_dq_strjoin(char *str, int *i,
								t_shell *shell, t_trim *trim)
{
	char	*tmp;
	char	*new_str;

	if (trim->res == NULL)
		trim->res = ft_substr(str, trim->start, *i - trim->start);
	new_str = ft_doublequotes_str(str, i, shell);
	tmp = trim->res;
	trim->res = gnl_strjoin(tmp, new_str);
	trim->start = *i;
}

static	void	ft_nqts_sq_strjoin(char *str, int *i, t_trim *trim)
{
	char	*tmp;
	char	*new_str;
	int		start;

	if (trim->res == NULL)
		trim->res = ft_substr(str, trim->start, *i - trim->start);
	*i = *i + 1;
	start = *i;
	while (str[*i] != '\'')
		*i = *i + 1;
	new_str = ft_substr(str, start, *i - start);
	tmp = trim->res;
	trim->res = gnl_strjoin(tmp, new_str);
	*i = *i + 1;
	trim->start = *i;
}

char			*ft_no_quotes_str(char *str, int *i, t_shell *shell)
{
	t_trim		trim;
	char		*output;

	trim.res = (char *)0;
	output = NULL;
	trim.start = *i;
	while (!ft_strchr("><|; ", str[*i]) && str[*i] != '\n' && str[*i] != '\0')
	{
		if (str[*i] == '$' && !ft_strchr(" ;\n", str[*i + 1]))
			ft_parse_dollar(str, i, &trim, shell);
		else if (str[*i] == '\\' && ft_strchr(" \\\'\"", str[*i + 1]))
			ft_strspecial(str, &trim, i, str[*i + 1]);
		else if (str[*i] == '\"' && ft_backslash_check(str, *i) % 2 == 0)
			ft_nqts_dq_strjoin(str, i, shell, &trim);
		else if (str[*i] == '\'' && ft_backslash_check(str, *i) % 2 == 0)
			ft_nqts_sq_strjoin(str, i, &trim);
		else
			*i = *i + 1;
	}
	output = ft_insert_nqt_output(str, *i, &trim);
	return (output);
}
