/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:20 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/05 11:08:39 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/* This function serves to find out where the pixels will be put
on the screen, and what sort of color will the pixel be based on the
number of iterations it has gone through. */
void	mandelbrot(t_img *img, t_point *p)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = -1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + p->i;
		zr = zr * zr - zi * zi + p->r;
		zi = tmp;
	}
	if (n >= 0 && n <= MAX_ITERATIONS - 1)
		my_mlx_pixel_put(img, p->x, p->y, bernstein_color(n));
	else
		my_mlx_pixel_put(img, p->x, p->y, 0x00FFFFFF);
}

/* With this function we are calling the mandelbrot function, and
are putting the result image to our mlx window. */
void	draw_mandelbrot(t_fractol *f, t_img *img)
{
	t_point	p;

	mlx_clear_window(f->mlx, f->mlx_win);
	p.y = -1;
	while (++p.y < HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
		{
			p.r = f->min_r + (double)p.x * (f->max_r - f->min_r) / WIDTH;
			p.i = f->min_i + (double)p.y * (f->max_i - f->min_i) / HEIGHT;
			mandelbrot(img, &p);
		}
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, img->img, 0, 0);
}

/* After we have found out the pixels and put the image, it is time to
initialize the mlx window and see the result of our initialzed
mandelbrot set. */
void	init_mandelbrot(char **argv)
{
	t_fractol	f;
	t_img		img;

	f.mlx = mlx_init();
	if (f.mlx == NULL)
		return ;
	f.f_name = argv[1];
	f.min_r = -2.0;
	f.max_r = 2.0;
	f.min_i = -2.0;
	f.max_i = 2.0;
	f.mlx_win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	f.pimg = &img;
	draw_mandelbrot(&f, f.pimg);
	mlx_hook(f.mlx_win, EVENT_CLOSE_BTN, 0, &close_win, &f);
	mlx_key_hook(f.mlx_win, &key_hooks, &f);
	mlx_mouse_hook(f.mlx_win, &mouse_event, &f);
	mlx_loop(f.mlx);
}
