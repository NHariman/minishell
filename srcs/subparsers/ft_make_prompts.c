/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_prompts.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 20:18:42 by nhariman      #+#    #+#                 */
/*   Updated: 2020/12/06 02:35:35 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		ft_not_valid_prompt(char *str)
{
	int len;

	len = ft_strlen(str) - 1;
	while (str[len] == ' ')
		len--;
	if (ft_strchr("<>|", str[len]))
		return (ft_printf_err(
				"minishell: syntax error near unexpected token `;'\n"));
	else
		return (0);
}

static int		ft_is_open_pipe(char *str)
{
	int len;

	len = ft_strlen(str) - 1;
	while (str[len] == ' ')
		len--;
	if (str[len] == '|')
		return (ft_printf_err("minishell: multiline pipes not supported\n"));
	return (0);
}

static int		ft_valid_prompt(char **prompts, t_shell *shell)
{
	int i;

	i = 0;
	while (prompts[i + 1] != (char *)0)
	{
		if (ft_not_valid_prompt(prompts[i]) ||
		ft_invalid_line(prompts[i], shell, ";"))
			return (0);
		if (ft_invalid_pipe(prompts[i], shell))
			return (0);
		i++;
	}
	if (ft_is_open_pipe(prompts[i]))
		return (0);
	return (1);
}

static int		ft_has_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|' && ft_backslash_check(str, i) % 2 == 0)
			return (1);
		if (str[i] == '\"' && ft_backslash_check(str, i) % 2 == 0)
			ft_skip_quotes(str, &i, DQ);
		else if (str[i] == '\'' && ft_backslash_check(str, i) % 2 == 0)
			ft_skip_quotes(str, &i, SQ);
		else if (str[i] == '\\')
			i = i + 2;
		else
			i = i + 1;
	}
	return (0);
}

void			ft_make_prompts(char *str, t_shell *shell)
{
	int		i;
	char	**prompts;

	i = 0;
	prompts = ft_get_prompts(str);
	int k = 0;
	while (prompts[k] != (char *)0)
	{
		ft_printf("prompts[%i]: {%s}\n", k, prompts[k]);
		k++;
	}
	if (!ft_valid_prompt(prompts, shell))
	{
		shell->exit_code = 258;
		ft_free_array(prompts, ft_arrlen(prompts));
		return ;
	}
	while (prompts[i] != (char *)0)
	{
		if (ft_has_pipe(prompts[i]))
			ft_pipe_splitter(prompts[i], shell);
		else
			function_dispatcher(prompts[i], shell);
		ft_clear_shell(shell);
		i++;
	}
	ft_free_array(prompts, ft_arrlen(prompts));
	return ;
}
