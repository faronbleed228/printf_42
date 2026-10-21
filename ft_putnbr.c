/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:10:34 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 17:51:04 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	lenght;

	lenght = 0;
	if (n == 0)
		lenght++;
	while (n)
	{
		lenght++;
		n /= 10;
	}
	return (lenght);
}

static char	*ft_local_itoa(int n)
{
	long	nb;
	int		lenght;
	char	*ptr;

	nb = n;
	if (nb < 0)
		nb *= -1;
	lenght = ft_intlen(n);
	ptr = malloc(lenght + 1);
	if (!ptr)
		return (NULL);
	if (nb == 0)
		ptr[0] = '0';
	ptr[lenght] = '\0';
	while (nb > 0)
	{
		ptr[--lenght] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ptr);
}

void	ft_putnbr(t_format *format, char *str, int minus, int zeros)
{
	int	padding;

	padding = 0;
	if (format->width > format->total_lenght)
		padding = format->width - format->total_lenght;
	if (minus == 1 && (format->zero == 1 && format->has_precision != 1))
	{
		write(1, "-", 1);
		minus = 0;
	}
	if (format->minus != 1)
		ft_putwidth(format, padding);
	if (minus == 1 && (format->zero == 1 || format->has_precision == 1))
		write(1, "-", 1);
	while (zeros--)
		write(1, "0", 1);
	if (minus == 1 && format->zero != 1 && format->has_precision != 1)
		write(1, "-", 1);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (format->minus == 1)
		ft_putwidth(format, padding);
}

static int	ft_totallen(t_format *format, int len, int minus, int *zeros)
{
	if (format->has_precision)
	{
		if (0 > format->precision - len)
			*zeros = 0;
		else
			*zeros = format->precision - len;
	}
	else
		*zeros = 0;
	if (minus == 1)
		return (len + *zeros + 1);
	return (len + *zeros);
}

int	ft_nbrpadding(t_format *format, int n)
{
	char	*str;
	int		zeros;
	int		minus;

	str = ft_local_itoa(n);
	minus = 0;
	if (!str)
		return (0);
	if (n < 0)
	{
		minus = 1;
	}
	format->total_lenght = ft_totallen(format, ft_strlen(str), minus, &zeros);
	if (format->has_precision == 1 && format->precision == 0 && n == 0)
	{
		free(str);
		format->total_lenght = 0;
		if (format->width > format->total_lenght)
			ft_putwidth(format, format->width);
		return (ft_return_nbr(format, n));
	}
	ft_putnbr(format, str, minus, zeros);
	free(str);
	return (ft_return_nbr(format, n));
}
