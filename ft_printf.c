/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:25:28 by wcaetano          #+#    #+#             */
/*   Updated: 2022/07/23 16:16:53 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_marker(const char *marker, va_list args)
{
	marker++;
	if (*marker == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*marker == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*marker == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	else if (*marker == 'd' || *marker == 'i')
		return (ft_putnbr_base(va_arg(args, int), 10, DECIMAL_BASE));
	else if (*marker == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned), 10, DECIMAL_BASE));
	else if (*marker == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned), 16, LHEX_BASE));
	else if (*marker == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned), 16, UHEX_BASE));
	else if (*marker == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		tmp;
	size_t	i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		tmp = 1;
		if (*format == '%')
		{
			tmp = parse_marker(format, args);
			format += 2;
		}
		else
			write(1, format++, 1);
		i += tmp;
	}
	va_end(args);
	return (i);
}
