/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:44:53 by mdiestre          #+#    #+#             */
/*   Updated: 2025/05/12 13:30:50 by mdiestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> // write
# include <stdlib.h> // malloc free
# include <stdarg.h> // variadic functions
# include "libft.h" // libft

// Main print function
int		ft_printf(const char *format, ...);

// Auxiliary functions
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_int(int n);
int		ft_print_unsigned(unsigned int n);
char	*ft_utoa(unsigned int n);
char	*ft_itoa_base(unsigned int n, int base, int uppercase);
int		ft_print_hex(unsigned int n, int uppercase);
int		ft_print_ptr(void *ptr);
// int	print_percent(void);

#endif
