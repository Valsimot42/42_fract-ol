/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:25:58 by tbolkova          #+#    #+#             */
/*   Updated: 2022/10/26 16:27:14 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// writes the string (or 'null') and returns the length
int	process_string(char *c)
{
	if (!c)
		return (write(1, "(null)", 6));
	return (write(1, c, ft_strlen(c)));
}

// writes the pointer recursively (and the 0x) and returns the length
int	process_pointer(unsigned long int n)
{
	int	digit;
	int	length;

	digit = 0;
	length = 0;
	if (n / 16)
		length += process_pointer(n / 16);
	if (length == 0)
		length += write(1, "0x", 2);
	digit = n % 16;
	length += write(1, &"0123456789abcdef"[digit], 1);
	return (length);
}	

// writes the number recursively and returns the length
int	process_decimal(int n)
{
	long			new;
	int				length;
	int				flag;

	new = (long)n;
	length = 0;
	flag = 0;
	if (new < 0)
	{
		length += write(1, "-", 1);
		new = -new;
	}
	if (new / 10)
		length += process_decimal(new / 10);
	new = new % 10 + '0';
	length += write(1, &new, 1);
	return (length);
}

// writes the unsigned number recursively and returns the length
int	process_unsigned_decimal(unsigned int n)
{
	long		new;
	int			length;

	new = (long)n;
	length = 0;
	if (new / 10)
		length += process_decimal(new / 10);
	new = new % 10 + '0';
	length += write(1, &new, 1);
	return (length);
}

// writes the hex value recursively and returns the length
int	process_hex(unsigned int n, int flag)
{
	unsigned int	digit;
	int				length;

	digit = 0;
	length = 0;
	if (n >= 16)
		length += process_hex(n / 16, flag);
	digit = n % 16;
	if (flag == 0)
		length += write(1, &"0123456789abcdef"[digit], 1);
	else
		length += write(1, &"0123456789ABCDEF"[digit], 1);
	return (length);
}
