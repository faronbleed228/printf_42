/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:38:10 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 18:28:16 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpointer(t_format *format, char *str, int total_len, int zeros)
{
	int	padding;

	padding = 0;
	if (format->width - total_len > 0)
		padding = format->width - total_len;
	if (format->minus != 1)
		ft_putwidth(format, padding);
	write(1, "0x", 2);
	while (zeros--)
		write(1, "0", 1);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (format->minus == 1)
		ft_putwidth(format, padding);
}

int	ft_pointer_padding(t_format *format, unsigned long n, char *base)
{
	int		len;
	char	*str;
	int		zeros;
	int		total_lenght;

	if (n == 0)
		return (ft_putformatstr(format, "(nil)"));
	str = ft_base_atoi(n, base);
	if (!str)
		return (0);
	len = ft_strlen(str);
	zeros = 0;
	if (format->has_precision == 1 && 0 < format->precision - len)
		zeros = format->precision - len;
	total_lenght = len + zeros + 2;
	if (format->has_precision == 1 && format->precision == 0 && n == 0)
	{
		free(str);
		return (ft_return_pointer(format, n, total_lenght));
	}
	ft_putpointer(format, str, total_lenght, zeros);
	free(str);
	return (ft_return_pointer(format, n, total_lenght));
}
