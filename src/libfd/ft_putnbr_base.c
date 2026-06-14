/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:27:15 by hsouza-s          #+#    #+#             */
/*   Updated: 2026/06/14 15:16:02 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	ft_hex_format(int dig, char format)
{
	char	res;

	if (format == 'l')
		res = dig - 10 + 'a';
	else
		res = dig - 10 + 'A';
	return (res);
}

int	ft_putnbr_base(long long int n, int base, char format)
{
	long long int	n_long;
	char			buffer[12];
	int				dig;
	int				i;

	n_long = n;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	if (n_long < 0)
		n_long = -n_long;
	buffer[11] = '\0';
	i = 10;
	while (n_long > 0)
	{
		dig = n_long % base;
		buffer[i] = '0' + dig ;
		if (dig > 9)
			buffer[i] = ft_hex_format(dig, format);
		n_long /= base;
		i--;
	}
	i++;
	if (n < 0)
		buffer[--i] = '-';
	return (ft_putstr_fd(buffer + i, 1), 1);
}
