/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manupc <manupc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:40:11 by manupc            #+#    #+#             */
/*   Updated: 2025/05/07 19:21:12 by manupc           ###   ########.fr       */
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
int	print_char(char c);

#endif
