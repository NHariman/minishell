/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_err_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 17:31:04 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/28 23:40:56 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	pft_eputchar_fd(char c, int fd, int *count)
{
	ssize_t	output;

	output = 0;
	if (*count < 0)
		return ;
	output = write(fd, &c, 1);
	if (output < 0)
		*count = -1;
}

void	pft_eputstr_fd(char *s, int fd, int *count)
{
	int		length;
	ssize_t	output;

	output = 0;
	if (*count < 0)
		return ;
	if (s)
	{
		length = ft_strlen(s);
		output = write(fd, s, length);
		if (output < 0)
			*count = -1;
	}
}

void	ft_eprint_char(const char c, int *count, t_flag *flags)
{
	if (!flags->dash && !flags->zero)
		ft_epad(flags->pad - 1, count);
	if (flags->zero && !flags->dash)
		ft_epadzero(flags->pad - 1, count);
	pft_eputchar_fd(c, 2, count);
	if (*count < 0)
		return ;
	*count = *count + 1;
	if (flags->dash)
		ft_epad(flags->pad - 1, count);
}

/*
** undefined behaviour if not a literal string is given,
** but (null) is printed because
** that's what the real printf does.
*/

static size_t	set_strlen(t_flag *flags, const char *str)
{
	if ((size_t)flags->pre < ft_strlen(str))
		return ((size_t)flags->pre);
	else
		return (ft_strlen(str));
}

void	ft_eprint_str(const char *str, int *count, t_flag *flags)
{
	size_t		i;
	size_t		strlen;

	if (!str)
		str = "(null)";
	i = 0;
	strlen = set_strlen(flags, str);
	if (!flags->dash && !flags->zero && flags->pad > 0)
		ft_epad(flags->pad - strlen, count);
	if (flags->zero && !flags->dash)
		ft_epadzero(flags->pad - strlen, count);
	while (i < strlen)
	{
		pft_eputchar_fd(str[i], 2, count);
		if (*count < 0)
			return ;
		i++;
	}
	*count = *count + strlen;
	if (flags->dash)
		ft_epad(flags->pad - strlen, count);
}
