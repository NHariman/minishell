/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prompts.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 03:18:41 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/22 11:07:51 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_count_prompts(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (ft_strchr("\'\"", str[i]) && ft_backslash_check(str, i) % 2 == 0)
			ft_skip_quotes(str, &i, str[i]);
		else
			i = i + 1;
		if (str[i] == ';' && ft_backslash_check(str, i) % 2 == 0
			&& str[i + 1 + ft_iswhitespaces(str + i + 1)] != '\0')
			count++;
	}
	return (count);
}

static char	*ft_fill_single_prompt(char *str, int i, int *start,
	char *str_token)
{
	char	*prompt;

	prompt = ft_strtrimfree(ft_substr(str, *start, i - *start), str_token);
	*start = i + 1;
	return (prompt);
}

static void	check_prompt(char *str, int *i)
{
	if (ft_strchr("\'\"", str[*i]) && ft_backslash_check(str, *i) % 2 == 0)
		ft_skip_quotes(str, i, str[*i]);
	else
		*i = *i + 1;
}

char	**ft_fill_prompts(char **prompts, char *str, int len,
	char token)
{
	int		start;
	int		count;
	char	*str_token;
	int		i;

	start = 0;
	count = 0;
	str_token = ft_make_single_char_str(token);
	i = 0;
	while (str[i] != '\0' && count < len)
	{	
		check_prompt(str, &i);
		if (str[i] == token && ft_backslash_check(str, i) % 2 == 0
			&& str[i + 1 + ft_iswhitespaces(str + i + 1)] != '\0')
		{
			prompts[count] = ft_fill_single_prompt(str, i, &start, str_token);
			count++;
		}
	}
	prompts[count] = ft_strtrimfree(
			ft_substr(str, start, i - start), str_token);
	free(str_token);
	return (prompts);
}

char	**ft_get_prompts(char *str)
{
	int		len;
	char	**prompts;

	len = ft_count_prompts(str);
	prompts = (char **)malloc(sizeof(char *) * (len + 1));
	if (!prompts)
		ft_malloc_fail("ft_prompts");
	prompts[len] = (char *) 0;
	prompts = ft_fill_prompts(prompts, str, len, ';');
	if (!prompts)
		return (NULL);
	return (prompts);
}
