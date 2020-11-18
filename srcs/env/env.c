/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 17:45:23 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/18 20:52:42 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** first argument is executable
** every other argument thereafter is part of an argv that should be passed
** into the executable.
** use execv, this will return 0 if succesful, and -1 if error.
** shell->exit_err set to 126 for unable to execute. (unless you use a fork?)
*/

/*
** make a linked list of args if the first arg does not contain an = for
** VARIABLE=CONENT
** and execute the command while giving the envp and argv list, if
** that is the only command out there. If not, store it and wait for
** the redirection or pipe.
*/

int			env_main(char *str, t_shell *shell)
{
	int		i;
	char	*first_arg;

	i = 0;
	while (str[i] == ' ')
		i++;
	first_arg = ft_no_quotes_str(str, &i, shell);

	return (0);
}
