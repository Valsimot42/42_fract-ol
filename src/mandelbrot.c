/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:20 by stena-he          #+#    #+#             */
/*   Updated: 2022/11/29 15:26:49 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

void	draw_mandelbrot(t_fractol *f, t_img *img)
{
	t_point	p;

	mlx_clear_window(f->mlx, f->win);
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
	mlx_put_image_to_window(f->mlx, f->win, img->img, 0, 0);
}

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
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	f.pimg = &img;
	draw_mandelbrot(&f, f.pimg);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, &close_win, &f);
	mlx_key_hook(f.win, &key_hooks, &f);
	mlx_mouse_hook(f.win, &mouse_event, &f);
	mlx_loop(f.mlx);
}
