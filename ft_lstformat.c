/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 21:54:56 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 16:11:17 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_simple_atoi(const char *str, int *i)
{
	long	result;

	result = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - 48);
		(*i)++;
	}
	(*i)--;
	return ((int)result);
}

static void	ft_bonus1(t_format *format, const char *str, int *i)
{
	if (str[*i] == '-')
		format->minus = 1;
	else if (str[*i] == '0' && format->width == 0)
		format->zero = 1;
	else if (str[*i] == '.')
	{
		format->has_precision = 1;
		(*i)++;
		format->precision = ft_simple_atoi(str, i);
		format->zero = 0;
	}
	else if (str[*i] >= '0' && str[*i] <= '9')
		format->width = ft_simple_atoi(str, i);
	if (format->minus == 1)
		format->zero = 0;
}

static void	ft_init_all(t_format *format)
{
	format->precision = 0;
	format->has_precision = 0;
	format->minus = 0;
	format->space = 0;
	format->width = 0;
	format->zero = 0;
	format->total_lenght = 0;
}

t_format	*ft_lstformat(const char *str, int *i)
{
	t_format	*format;

	if (!str)
		return (NULL);
	format = ft_calloc(1, sizeof(t_format));
	if (!format)
		return (NULL);
	ft_init_all(format);
	format->width = 0;
	while (str[*i] && !ft_strchr("cspdiuxX%", str[*i]))
	{
		ft_bonus1(format, str, i);
		(*i)++;
	}
	format->conv = str[*i];
	return (format);
}
