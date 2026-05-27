/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:36:42 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 19:04:15 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parsing_loop(va_list args, int *i, const char *str)
{
	int			count;
	t_format	*format;

	count = 0;
	format = NULL;
	while (str[*i])
	{
		if (str[*i] == '%' && str[*i + 1] != '\0')
		{
			(*i)++;
			format = ft_lstformat(str, i);
			if (format)
			{
				count += ft_putvar(format, args);
				free(format);
			}
		}
		else if (str[*i] != '%')
			count += write(1, &str[*i], 1);
		(*i)++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	count = ft_parsing_loop(args, &i, str);
	va_end(args);
	return (count);
}
