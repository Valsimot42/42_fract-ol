/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:28:50 by tbolkova          #+#    #+#             */
/*   Updated: 2022/09/21 16:29:19 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "Libft/libft.h"

int		ft_printf(const char *str, ...);
char	*pointer_to_string(unsigned long int c);
int		process_string(char *c);
int		process_pointer(unsigned long int n);
int		process_decimal(int n);
int		process_unsigned_decimal(unsigned int n);
int		process_hex(unsigned int n, int flag);
#endif 