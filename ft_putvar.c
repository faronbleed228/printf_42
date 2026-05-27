/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:44:26 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/12 09:58:42 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvar(t_format *format, va_list args)
{
	int	count;

	count = 0;
	if (format->conv == 'c')
		count += ft_putchar(format, va_arg(args, int));
	else if (format->conv == 's')
		count += ft_putformatstr(format, va_arg(args, char *));
	else if (format->conv == 'i' || format->conv == 'd')
		count += ft_nbrpadding(format, va_arg(args, int));
	else if (format->conv == '%')
		count += ft_putchar(format, '%');
	else if (format->conv == 'u')
		count += ft_putunsint(format, va_arg(args, unsigned int));
	else if (format->conv == 'x')
		count += ft_putnbr_base(format, va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (format->conv == 'X')
		count += ft_putnbr_base(format, va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (format->conv == 'p')
	{
		count += ft_pointer_padding(format, (unsigned long)va_arg(args, void *),
				"0123456789abcdef");
	}
	return (count);
}
