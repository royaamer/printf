/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roababne <roababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:07:24 by roababne          #+#    #+#             */
/*   Updated: 2026/01/08 13:34:33 by roababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_percent(const char *fmt, int *i, va_list *ap)
{
	int	count;

	(*i)++;
	if (!fmt[*i])
		return (0);
	count = ft_dispatch(fmt[*i], ap);
	(*i)++;
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, fmt);
	i = 0;
	count = 0;
	while (fmt && fmt[i])
	{
		if (fmt[i] == '%')
			count += ft_handle_percent(fmt, &i, &ap);
		else
			count += (int)write(1, &fmt[i++], 1);
	}
	va_end(ap);
	return (count);
}
