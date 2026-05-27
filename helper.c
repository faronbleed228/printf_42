/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:37:46 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 18:05:48 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*copy;

	copy = (unsigned char *)str;
	while (len > 0)
	{
		*copy = (unsigned char)c;
		len--;
		copy++;
	}
	return (str);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	max;

	max = -1;
	if (nelem == 0 || elsize == 0)
	{
		ptr = malloc(1);
		return (ptr);
	}
	if (elsize != 0 && nelem > max / elsize)
		return (NULL);
	ptr = malloc(elsize * nelem);
	if (ptr != NULL)
		ft_memset(ptr, 0, elsize * nelem);
	return (ptr);
}
