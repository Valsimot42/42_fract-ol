/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:01:18 by tbolkova          #+#    #+#             */
/*   Updated: 2022/08/01 19:01:33 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// detects the formatting flag and passes the value
// to the corresponding function 
int	format_handler(const char *str, int i, va_list args)
{
	int		length;
	char	c;

	length = 0;
	if (str[i] == 'c')
	{
		c = va_arg(args, int);
		length = write (1, &c, 1);
	}
	else if (str[i] == 's')
		length = process_string(va_arg(args, char *));
	else if (str[i] == 'p')
		length = process_pointer(va_arg(args, unsigned long int));
	else if (str[i] == 'd' || str[i] == 'i')
		length = process_decimal(va_arg(args, int));
	else if (str[i] == 'u')
		length = process_unsigned_decimal(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		length = process_hex(va_arg(args, unsigned int), 0);
	else if (str[i] == 'X')
		length = process_hex(va_arg(args, unsigned int), 1);
	else if (str[i] == '%')
		length = write(1, "%", 1);
	return (length);
}

// reads all function arguments into args. If a % is encountered,
// the function calls the format_handler in order to format the output.
// Else just prints the characters of the string passed as the first argument.
int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(arg, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			length += format_handler(string, i, arg);
		}
		else
			length += write(1, &string[i], 1);
		i++;
	}
	va_end(arg);
	return (length);
}
