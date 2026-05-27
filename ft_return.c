/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:52:22 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 18:14:20 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_return_nbr(t_format *format, int n)
{
	if (format->has_precision == 1 && format->precision == 0 && n == 0)
	{
		if (format->width > format->total_lenght)
			return (format->width);
		return (0);
	}
	if (format->width > format->total_lenght)
		return (format->width);
	return (format->total_lenght);
}

int	ft_return_unsnbr(t_format *format, unsigned int n)
{
	if (format->has_precision == 1 && format->precision == 0 && n == 0)
	{
		if (format->width > format->total_lenght)
			return (format->width);
		return (0);
	}
	if (format->width > format->total_lenght)
		return (format->width);
	return (format->total_lenght);
}

int	ft_return_pointer(t_format *format, unsigned long n, int total_len)
{
	if (format->has_precision == 1 && format->precision == 0 && n == 0)
	{
		if (format->width > total_len)
			return (format->width);
		return (0);
	}
	if (format->width > total_len)
		return (format->width);
	return (total_len);
}

int	ft_return_str(t_format *format, int len)
{
	if (format->width > len)
		return (format->width);
	return (len);
}
