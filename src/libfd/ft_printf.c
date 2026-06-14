/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:34:27 by hsouza-s          #+#    #+#             */
/*   Updated: 2026/06/14 15:15:54 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_format(va_list ptr, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_putchar_fd(va_arg(ptr, int), 1);
	else if (type == 's')
		len = ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (type == 'p')
		len = ft_long_to_hex(va_arg(ptr, unsigned long));
	else if (type == 'd')
		len = ft_putnbr_base(va_arg(ptr, int), 10, 'l');
	else if (type == 'i')
		len = ft_putnbr_base(va_arg(ptr, int), 10, 'l');
	else if (type == 'u')
		len = ft_putnbr_base(va_arg(ptr, unsigned int), 10, 'l');
	else if (type == 'x')
		len = ft_putnbr_base(va_arg(ptr, unsigned int), 16, 'l');
	else if (type == 'X')
		len = ft_putnbr_base(va_arg(ptr, unsigned int), 16, 'L');
	else if (type == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(arg, str[i]);
		}	
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}
