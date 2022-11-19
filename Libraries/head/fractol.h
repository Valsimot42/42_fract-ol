/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:32 by tbolkova          #+#    #+#             */
/*   Updated: 2022/11/19 13:31:02 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
#define FRACTOL_H


typedef struct	s_data{			// This is a structure. It allows us to put data items of different kinds
	void	*img;				// under one variable. To access any member of a structure, we use the
	char	*addr;				// member (.) operator. The member access operator is coded as a period
	int		bits_per_pixel;		// between the structure variable name and the structure member that we
	int		line_length;		// wish to access. You would use 'struct'keyword to define variables of
	int		endian;				// structure type.
}				t_data;			//


#include "../../mlx/mlx.h"
#include "../Ft_printf/ft_printf.h"
#include "../Ft_printf/Libft/libft.h"
// #include "../../mlx_linux_/mlx_int.h"



#endif