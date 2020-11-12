/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotations_parser.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 20:52:54 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/12 21:51:22 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_doublequotes_str(char *str, int *i, t_shell *shell)
{
	int		start;
	char	*tmp;
	char	*output;
	char	*old_str;

	start = *i + 1;
	*i = *i + 1;
	while (str[*i] != '\"' && str[*i - 1] != '\\' ||
		(str[*i] == '\"' && ft_backslash_check(str, *i) % 2 == 0))
	{
		if (str[*i] == '\\')
		{
			if (ft_strchr("\\\"\'$", str[*i + 1]))
			{
				tmp = ft_substr(str, start, *i - start);
				start = *i + 1;
				if (output == NULL)
					output = ft_stdup(tmp);
				else
				{
					old_str = output;
					output = gnl_strjoin(old_str, tmp);
					free(old_str);
				}
			}
		}
		*i = *i + 1;
	}
}