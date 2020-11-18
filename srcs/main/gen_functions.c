<<<<<<< Updated upstream
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 03:52:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/17 16:06:20 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_rm_endline(char *str)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = ft_substr(str, 0, len - 1);
	return (new);
}

int		exit_minishell(void)
{
	ft_printf("exit\n");
	exit(0);
}

char	*ft_find_arg(char *cmd, char *str, int *i)
{
	char	*word;
	t_qts	qts;

	word = cmd;
	ft_set_qts(&qts);
	ft_qt_line(str, &qts, i);
	while (!ft_strchr("$><;| \n\0", str[*i]))
		*i = *i + 1;
	return (word);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 03:52:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/14 19:28:30 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_rm_endline(char *str)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = ft_substr(str, 0, len - 1);
	return (new);
}

int		exit_minishell(void)
{
	ft_printf("exit\n");
	exit(0);
}

void	ft_wordlow(char **line)
{
	int start;

	start = 0;
	while (line[0][start] != '\0')
	{
		if (!ft_isalpha(line[0][start]))
			break ;
		line[0][start] = ft_tolower(line[0][start]);
		start++;
	}
}

char	*ft_find_arg(char *cmd, char *str, int *i)
{
	char	*word;
	t_qts	qts;

	word = cmd;
	ft_set_qts(&qts);
	ft_qt_line(str, &qts, i);
	while (!ft_strchr("$><;| \n\0", str[*i]))
		*i = *i + 1;
	return (word);
}
>>>>>>> Stashed changes
