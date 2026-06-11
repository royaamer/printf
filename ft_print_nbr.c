/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roababne <roababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:59:01 by roababne          #+#    #+#             */
/*   Updated: 2026/01/08 13:17:20 by roababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n > 9)
		count += ft_print_nbr(n / 10);
	c = (n % 10) + '0';
	count += ft_print_char(c);
	return (count);
}
