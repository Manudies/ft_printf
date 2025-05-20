/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:29:21 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/20 11:45:26 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
}

static const char	*parse_number(const char *format, int *value)
{
	*value = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static const char	*parse_dot(const char *format, t_flags *flags)
{
	flags->dot = 1;
	format++;
	if (ft_isdigit(*format))
		format = parse_number(format, &flags->precision);
	else
		flags->precision = 0;
	return (format - 1);
}

const char	*parse_flags(const char *format, t_flags *flags)
{
	init_flags(flags);
	while (*format)
	{
		if (*format == '-')
			flags->minus = 1;
		else if (*format == '0' && flags->width == 0 && flags->dot == 0)
			flags->zero = 1;
		else if (*format == '#')
			flags->hash = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == ' ')
			flags->space = 1;
		else if (*format == '.')
			format = parse_dot(format, flags);
		else if (ft_isdigit(*format))
			format = parse_number(format, &flags->width) - 1;
		else
			break ;
		format++;
	}
	return (format);
}
