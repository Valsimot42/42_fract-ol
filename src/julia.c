/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:38 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/05 11:14:07 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/* This function serves to find out where the pixels will be put
on the screen, and what sort of color will the pixel be based on the
number of iterations it has gone through. */
void	julia(t_fractol *f, t_img *img, t_point *p)
{
	int		n;
	double	tmp;

	n = -1;
	while (++n < MAX_ITERATIONS)
	{
		if ((p->r * p->r + p->i * p->i) > 4.0)
			break ;
		tmp = 2 * p->r * p->i + f->ki;
		p->r = p->r * p->r - p->i * p->i + f->kr;
		p->i = tmp;
	}
	if (n >= 0 && n <= MAX_ITERATIONS - 1)
		my_mlx_pixel_put(img, p->x, p->y, bernstein_color(n));
	else
		my_mlx_pixel_put(img, p->x, p->y, 0x00FFFFFF);
}

/* With this function we are calling the julia function, and
are putting the result image to our mlx window. */
void	draw_julia(t_fractol *f, t_img *img)
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
			julia(f, img, &p);
		}
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, img->img, 0, 0);
}

void	assign_julia(t_fractol *f, char **argv)
{
	f->f_name = argv[1];
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
}

/* After we have found out the pixels and put the image, it is time to
initialize the mlx window and see the result of our initialzed julia set. */
void	init_julia(char **argv)
{
	t_fractol	f;
	t_img		img;

	f.mlx = mlx_init();
	if (f.mlx == NULL)
		return ;
	assign_julia(&f, argv);
	if (!ft_strncmp(argv[1], "julia", 6))
	{
		f.kr = ft_atod(argv[2]);
		f.ki = ft_atod(argv[3]);
	}
	f.mlx_win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Julia Set");
	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	f.pimg = &img;
	draw_julia(&f, f.pimg);
	mlx_hook(f.mlx_win, EVENT_CLOSE_BTN, 0, &close_win, &f);
	mlx_key_hook(f.mlx_win, &key_hooks, &f);
	mlx_mouse_hook(f.mlx_win, &mouse_event, &f);
	mlx_loop(f.mlx);
}
