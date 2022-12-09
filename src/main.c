/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/05 10:58:43 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/* Initializing mandelbrot or julia.
If "help" is written, or if number of arguments is incorrect,
or if anything else is written, function help will be initialized. */
int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 4)
	{
		print_help();
		return (0);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11) && argc == 2)
		init_mandelbrot(argv);
	else if (!ft_strncmp(argv[1], "julia", 6) && argc == 4)
		init_julia(argv);
	else if (!ft_strncmp(argv[1], "help", 5))
		print_help();
	else
	{
		ft_printf("You done fucked up.\n\n");
		print_help();
	}
	return (0);
}
