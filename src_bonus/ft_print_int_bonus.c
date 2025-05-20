/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:31:22 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/20 12:32:43 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_left(t_format f, int n, t_flags *flags)
{
	int		printed;
	char	pad;

	printed = 0;
	pad = ' ';
	if (flags->zero && !flags->dot)
		pad = '0';
	if (!flags->minus && flags->width > f.total_len)
	{
		if (pad == '0' && f.sign && !f.suppress)
		{
			write_sign(n, flags, &printed);
			f.sign = 0;
		}
		printed += print_padding(pad, flags->width - f.total_len);
	}
	if (f.sign && !f.suppress)
		write_sign(n, flags, &printed);
	return (printed);
}

int	print_right(t_format f, t_flags *flags)
{
	if (flags->minus && flags->width > f.total_len)
		return (print_padding(' ', flags->width - f.total_len));
	return (0);
}

int	ft_print_int_bonus(int n, t_flags *flags)
{
	int			printed;
	t_format	f;

	f.nbr_len = get_nbr_len(n);
	f.sign = (n < 0 || flags->plus || flags->space);
	f.suppress = (flags->precision == 0 && n == 0);
	if (flags->precision > f.nbr_len - (n < 0))
		f.content_len = flags->precision;
	else
		f.content_len = f.nbr_len - (n < 0);
	if (f.suppress)
		f.content_len = 0;
	f.total_len = f.content_len;
	if (!f.suppress)
		f.total_len += f.sign;
	printed = print_left(f, n, flags);
	printed += handle_number(n, flags, f.nbr_len);
	printed += print_right(f, flags);
	return (printed);
}
