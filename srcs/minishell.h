/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:18:06 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/15 19:48:20 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _GNU_SOURCE
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

# include "yusha.h"
# include "niks.h"
# include "libft/libft.h"

t_shell	g_shell;

/*
** 1: hangup
** 2: interrupt
** 3: Quit
** 4: illegal instruction
** 5: trace trap
** 6: abort
*/

# define SIGHUP  1
# define SIGINT  2
# define SIGQUIT 3
# define SIGILL  4
# define SIGTRAP 5
# define SIGABRT 6
# define SIGKILL 9

#endif
