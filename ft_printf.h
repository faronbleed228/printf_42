/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:22:09 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/05/27 18:40:25 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	char	conv;
	int		width;
	int		minus;
	int		zero;
	int		space;
	int		precision;
	int		has_precision;
	int		total_lenght;

}			t_format;

int			ft_printf(const char *str, ...);

t_format	*ft_lstformat(const char *str, int *i);

int			ft_nbrpadding(t_format *format, int n);
int			ft_pointer_padding(t_format *format, unsigned long n, char *base);
int			ft_putformatstr(t_format *format, char *str);
void		ft_putwidth(t_format *format, int len);

size_t		ft_strlen(const char *str);
char		*ft_base_atoi(unsigned long n, char *base);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t nelem, size_t elsize);

int			ft_return_nbr(t_format *format, int n);
int			ft_return_unsnbr(t_format *format, unsigned int n);
int			ft_return_pointer(t_format *format, unsigned long n, int total_len);
int			ft_return_str(t_format *format, int len);

int			ft_putstr(char *str);
int			ft_putchar(t_format *format, int c);
int			ft_putnbr_base(t_format *format, unsigned int n, char *base);
void		ft_putnbr(t_format *format, char *str, int minus, int zeros);
int			ft_putvar(t_format *format, va_list args);
int			ft_putunsint(t_format *format, unsigned int n);

#endif
