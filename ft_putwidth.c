/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:24:49 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/30 08:41:07 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwidth(t_format *format, int len)
{
	while (len-- > 0)
	{
		if (format->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}
