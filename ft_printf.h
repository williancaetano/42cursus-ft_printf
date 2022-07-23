/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:29:01 by wcaetano          #+#    #+#             */
/*   Updated: 2022/07/23 16:15:52 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define LHEX_BASE "0123456789abcdef"
# define UHEX_BASE "0123456789ABCDEF"
# define DECIMAL_BASE "0123456789"

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long long n);
int	ft_putnbr_base(long long n, int base_n, char *base);
int	ft_putchar(int c);

#endif