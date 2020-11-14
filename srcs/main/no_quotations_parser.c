/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_quotations_parser.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 13:44:13 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/14 15:11:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_insert_nqt_output(char *str, int i, t_trim *trim)
{
	char		*output;
	char		*old_str;

	output = NULL;
	old_str = NULL;
	if (trim->res == '\0')
		output = ft_substr(str, trim->start, i - trim->start);
	else
	{
		old_str = trim->res;
		output = ft_strjoin(old_str,
			ft_substr(str, trim->start, i - trim->start));
	}
	return (output);
}

char		*ft_no_quotes_str(char *str, int *i, t_shell *shell)
{
	t_trim		*trim;
	char		*output;

	trim = ft_calloc(1, sizeof(t_trim));
	output = NULL;
	trim->start = *i;
	while (!ft_strchr("><|; ", str[*i]) && str[*i] != '\n' && str[*i] != '\0')
	{
		if (str[*i] == '$')
			ft_parse_dollar(str, i, trim, shell);
		else if (str[*i] == '\\' && ft_strchr("\\\'\"", str[*i + 1]))
			ft_strspecial(str, trim, i, str[*i + 1]);
		else
			*i = *i + 1;
	}
	output = ft_insert_nqt_output(str, *i, trim);
	free(trim);
	return (output);
}
