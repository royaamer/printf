/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roababne <roababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:51:23 by roababne          #+#    #+#             */
/*   Updated: 2026/01/08 13:31:10 by roababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr_hex(unsigned long n)
{
	const char	*base;
	int			count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_print_ptr_hex(n / 16);
	count += ft_print_char(base[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = 0;
	addr = (unsigned long)ptr;
	count += ft_print_str("0x");
	count += ft_print_ptr_hex(addr);
	return (count);
}
