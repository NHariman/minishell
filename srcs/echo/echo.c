/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 22:32:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int     check_n(char* str)
{
	int i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	else
		return(0);
	if (str[i] == 'n')
	{
		while (str[i] == 'n')
			i++;
	}
	if (str[i] == ' ')
		return (1);
	return (0);
}

int     lenght_n(char* str)
{
	int i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	else
		return (0);
	if (str[i] == 'n')
	{
		while (str[i] == 'n')
			i++;
	}
	if (str[i] == ' ')
		return (i);
	return (0);
}

void    no_str(t_struct_m *Echo, char* str)
{
	int     y   =   Echo->i;
	int     len =   0;
	char*   tmp =   NULL;

	printf("%i |%s|\n", Echo->i, str);
	y = Echo->i;
	while (str[Echo->i] != '\0')
	{
		len++;
		Echo->i++;
	}
	tmp = (char *)malloc((len + 1) * sizeof(char));
	len = 0;
	if (tmp != NULL)
	{
		while (str[y])
		{
			tmp[len] = str[y];
			y++;
			len++;
		}
		Echo->cache = ft_strjoin(Echo->cache, tmp);
		printf("cache = %s\n", Echo->cache);
	}
		free(tmp);
}

void        set_value(t_struct_m *Echo)
{
	Echo->cache = ft_strdup("");
	Echo->i       = 0;
	Echo->path    = 0;
	Echo->single  = 0;
	Echo->Double  = 0;
	Echo->end     = 0;
	Echo->len     = 0;
	Echo->stat    = 0;
}
char       *echo_main(char  *str)
{
	t_struct_m *Echo;

	Echo = ft_calloc(1, sizeof(t_struct_m));

	set_value(Echo);
	Echo->end = check_n(str);
	if (Echo->end == 1)
		Echo->i = lenght_n(str); /*now it knows when -n has ended */
	while (str[Echo->i] == ' ')
		Echo->i++;
	while (str[Echo->i])
	{
		if (str[Echo->i] != '\"' || str[Echo->i] != '\'')
			no_str(Echo, str);
	}
	return (Echo->cache);
}

