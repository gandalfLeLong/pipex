/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:49:26 by cmathot           #+#    #+#             */
/*   Updated: 2024/04/06 14:03:18 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_adress(int base, unsigned long n, int fd)
{
	int	size;

	size = 0;
	if (n >= 16)
		size += ft_putnbr_adress(base, n / 16, fd);
	if (!base)
		size += ft_putchar("0123456789abcdef"[n % 16], fd);
	else
		size += ft_putchar("0123456789ABCDEF"[n % 16], fd);
	return (size);
}

int	ft_is_in(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'd')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == '%')
		return (1);
	return (0);
}

int	ft_table_of_functions(char c, va_list ap, int fd)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int), fd));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *), fd));
	else if (c == 'p')
	{
		ft_putstr("0x", fd);
		return (ft_putnbr_adress(0, va_arg(ap, unsigned long), fd) + 2);
	}
	else if (c == 'd')
		return (ft_putnbr(va_arg(ap, int), fd));
	else if (c == 'i')
		return (ft_putnbr(va_arg(ap, int), fd));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int), fd));
	else if (c == 'x')
		return (ft_putnbr_hexa(0, va_arg(ap, unsigned int), fd));
	else if (c == 'X')
		return (ft_putnbr_hexa(1, va_arg(ap, unsigned int), fd));
	else
		return (ft_putchar('%', fd));
}

int	ft_printf(int fd, const	char *format, ...)
{
	int		i;
	int		size;
	va_list	ap;

	i = 0;
	size = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_is_in(format[i + 1]))
			size += ft_table_of_functions(format[++i], ap, fd);
		else
			size += write(fd, format + i, 1);
		i++;
	}
	va_end(ap);
	return (size);
}
