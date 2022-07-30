/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:07:10 by wcaetano          #+#    #+#             */
/*   Updated: 2022/07/30 18:36:35 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_abs(int num)
{
	if (num > 0)
		return (num);
	else
		return (-num);
}

int	ft_putstr(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	ft_putnbr_base(long long n, int base_n, char *base)
{
	int		i;
	char	buf[100];
	int		chars;

	i = 0;
	chars = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
		chars += write(1, "-", 1);
	while (n)
	{
		buf[i++] = base[ft_abs(n % base_n)];
		chars++;
		n /= base_n;
	}
	while (i--)
		write(1, buf + i, 1);
	return (chars);
}

int	ft_putptr(unsigned long long n)
{
	int		i;
	char	buf[20];
	int		chars;
	char	*base;

	i = 0;
	base = LHEX_BASE;
	chars = 0;
	write(1, "0x", 2);
	if (n == 0)
		return (write(1, "0", 1) + 2);
	while (n)
	{
		buf[i++] = base[n % 16];
		chars++;
		n /= 16;
	}
	while (i--)
		write(1, buf + i, 1);
	return (chars + 2);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
