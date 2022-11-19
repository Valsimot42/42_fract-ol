/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:59:48 by tbolkova          #+#    #+#             */
/*   Updated: 2022/11/19 13:31:24 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fractol.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	my_mlx_pixel_put(&img, 500, 499, 0x00FF0000);
	my_mlx_pixel_put(&img, 500, 498, 0x00FF0000);
	my_mlx_pixel_put(&img, 500, 497, 0x00FF0000);
	my_mlx_pixel_put(&img, 500, 496, 0x00FF0000);
	my_mlx_pixel_put(&img, 500, 495, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

