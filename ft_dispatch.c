/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roababne <roababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:08:22 by roababne          #+#    #+#             */
/*   Updated: 2026/01/08 13:08:48 by roababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(*ap, int)));
	if (spec == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_nbr(va_arg(*ap, int)));
	if (spec == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), spec));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	if (spec == '%')
		return (ft_print_char('%'));
	return (ft_print_char(spec));
}
