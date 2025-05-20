/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:41:30 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/20 11:46:13 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_format(const char *format, va_list args)
{
	t_flags	flags;
	int		printed;

	format = parse_flags(format, &flags);
	printed = 0;
	if (*format == 'd' || *format == 'i')
		printed += ft_print_int_bonus(va_arg(args, int), &flags);
	else if (*format)
		printed += write(1, format, 1);
	return (printed);
}
