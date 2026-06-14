/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:30:15 by hsouza-s          #+#    #+#             */
/*   Updated: 2023/05/27 17:31:10 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_long_to_hex(unsigned long ptr)
{
	unsigned long	long_min;
	unsigned long	long_max;

	long_min = 9223372036854775808U;
	long_max = 18446744073709551615U;
	if (ptr == long_min)
	{
		write(1, "0x8000000000000000", 18);
		return (18);
	}
	else if (ptr == long_max)
	{
		write(1, "0xffffffffffffffff", 18);
		return (18);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_putnbr_base(ptr, 16, 'l') + 2);
	}
}
