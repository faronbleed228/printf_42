/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:43:26 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 18:40:47 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned long n)
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

static char	*ft_unitoa(unsigned int n)
{
	unsigned long	nb;
	int				lenght;
	char			*ptr;

	nb = n;
	lenght = ft_intlen(nb);
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

int	ft_putunsint(t_format *format, unsigned int n)
{
	char	*str;
	int		len;
	int		zeros;

	str = ft_unitoa((unsigned int)n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	zeros = 0;
	if (format->has_precision == 1 && 0 < format->precision - len)
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
