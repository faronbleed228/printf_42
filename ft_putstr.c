/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:11:11 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 18:39:24 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(t_format *format, int c)
{
	if (format->minus != 1)
		ft_putwidth(format, format->width - 1);
	write(1, &c, 1);
	if (format->minus == 1)
		ft_putwidth(format, format->width - 1);
	if (format->width > 1)
		return (format->width);
	return (1);
}

static int	ft_putstrpers(t_format *format, const char *str)
{
	char	c;
	int		len;
	int		i;

	i = 0;
	if (!str)
	{
		len = ft_putstrpers(format, "(null)");
		return (ft_return_str(format, len));
	}
	len = ft_strlen(str);
	if (len > format->precision)
		len = format->precision;
	if (format->minus != 1)
		ft_putwidth(format, format->width - len);
	while (len > i)
	{
		c = str[i++];
		write(1, &c, 1);
	}
	if (format->minus == 1)
		ft_putwidth(format, format->width - len);
	return (ft_return_str(format, len));
}

int	ft_putformatstr(t_format *format, char *str)
{
	int		lenght;
	char	c;

	if (format->has_precision == 1)
	{
		lenght = ft_putstrpers(format, str);
		return (ft_return_str(format, lenght));
	}
	if (!str)
	{
		ft_putformatstr(format, "(null)");
		return (ft_return_str(format, 6));
	}
	lenght = ft_strlen(str);
	if (format->minus != 1)
		ft_putwidth(format, format->width - lenght);
	while (*str)
	{
		c = *str++;
		write(1, &c, 1);
	}
	if (format->minus == 1)
		ft_putwidth(format, format->width - lenght);
	return (ft_return_str(format, lenght));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
