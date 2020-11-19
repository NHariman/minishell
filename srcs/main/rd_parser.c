/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_parser.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 18:26:39 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/19 18:11:10 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	fake_rd_main(char *str, t_shell *shell)
{
	t_shell *sholl;

	sholl = shell;
	ft_printf("redirect str: {%s}\n", str);
}

void		ft_rd_parser(char *str, int *i, t_shell *shell)
{
	int		start;
	char	*rd_str;

	start = *i;
	while (str[*i] != '\n' && str[*i] != '\0' && !ft_strchr("|;", str[*i]))
		*i = *i + 1;
	if (start == *i || *i == 0)
		rd_str = ft_strdup("\n");
	else
		rd_str = ft_substr(str, start, *i - start);
	rd_main(rd_str, shell);
}

// #include "../minishell.h"

// static void	yushua_function(char *str)
// {
// 	ft_printf("string str: {%s}\n", str);
// }

// void		ft_rd_parser(char *str, int *i, t_shell *shell)
// {
// 	int		start;
// 	char	*rd_str;

// 	start = *i;
// 	while (str[*i] != '\n' && str[*i] != '\0' && !ft_strchr("|;", str[*i]))
// 		*i = *i + 1;
// 	if (start == *i || *i == 0)
// 		rd_str = ft_strdup("\n");
// 	else
// 		rd_str = ft_substr(str, start, *i - start);
// 	shell->rd_r = ft_stdup(rd_main(rd_str, shell));
// 	free(rd_str);
// 	shell->check.rd = 1;
// 	if (ft_strchr("\n;\0", str[*i]))
// 		ft_rd_output(shell->rd_r);
// }