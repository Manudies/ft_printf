/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:50:19 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/28 12:28:28 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_nbr_len(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	write_sign(int n, t_flags *flags, int *printed)
{
	if (n < 0)
		*printed += write(1, "-", 1);
	else if (flags->plus)
		*printed += write(1, "+", 1);
	else if (flags->space)
		*printed += write(1, " ", 1);
}

int	print_padding(char c, int times)
{
	int	count;

	count = 0;
	while (times-- > 0)
		count += write(1, &c, 1);
	return (count);
}

int	handle_number(int n, t_flags *flags, int nbr_len)
{
	int		total;
	int		prec_zeros;
	char	*num;

	total = 0;
	prec_zeros = flags->precision - (nbr_len - (n < 0));
	if (prec_zeros > 0)
		total += print_padding('0', prec_zeros);
	if (flags->precision == 0 && n == 0)
		return (total);
	num = ft_itoa(n);
	if (!num)
		return (total);
	if (n < 0)
		num++;
	total += write(1, num, ft_strlen(num));
	if (n < 0)
		num--;
	free(num);
	return (total);
}
