/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:26:24 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 17:58:42 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long n)
{
	int	lenght;

	lenght = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		lenght++;
	}
	return (lenght);
}

char	*ft_base_atoi(unsigned long n, char *base)
{
	int		base_len;
	int		lenght;
	char	*str;

	base_len = ft_strlen(base);
	lenght = ft_hexlen(n);
	str = malloc(lenght + 1);
	if (!str)
		return (NULL);
	str[lenght--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n)
	{
		str[lenght--] = base[(n % base_len)];
		n /= base_len;
	}
	return (str);
}

int	ft_putnbr_base(t_format *format, unsigned int n, char *base)
{
	int		len;
	char	*str;
	int		zeros;

	str = ft_base_atoi(n, base);
	if (!str)
		return (0);
	len = ft_strlen(str);
	zeros = 0;
	if (format->has_precision == 1 && 0 < (format->precision - len))
		zeros = format->precision - len;
	format->total_lenght = len + zeros;
	if (format->has_precision == 1 && format->precision == 0 && n == 0)
	{
		free(str);
		format->total_lenght = 0;
		if (format->width > format->total_lenght)
			ft_putwidth(format, format->width);
		return (ft_return_unsnbr(format, n));
	}
	ft_putnbr(format, str, 0, zeros);
	free(str);
	return (ft_return_unsnbr(format, n));
}
