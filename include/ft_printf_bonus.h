/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:32:35 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/20 13:08:32 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

// Struct to store parsed format flags
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	dot;
	int	hash;
	int	plus;
	int	space;
}	t_flags;

// Struct to hold calculated format parameters for %d
typedef struct s_format
{
	int	nbr_len;
	int	sign;
	int	suppress;
	int	content_len;
	int	total_len;
}	t_format;

// Flag parser
const char	*parse_flags(const char *format, t_flags *flags);

// Entry points
int			ft_printf(const char *format, ...);
int			ft_parse_format(const char *format, va_list args);

// Extended %d printing with flags
int			ft_print_int_bonus(int n, t_flags *flags);

// Helper functions for %d with flags
int			get_nbr_len(int n);
void		write_sign(int n, t_flags *flags, int *printed);
int			print_padding(char c, int times);
int			handle_number(int n, t_flags *flags, int nbr_len);
int			print_left(t_format f, int n, t_flags *flags);
int			print_right(t_format f, t_flags *flags);

#endif