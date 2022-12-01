/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:38 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/25 12:09:57 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

void	draw_julia(t_fractol *f, t_img *img)
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
			julia(f, img, &p);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, img->img, 0, 0);
}

void	assign_julia(t_fractol *f, char **argv)
{
	f->f_name = argv[1];
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
}

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
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Julia Set");
	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	f.pimg = &img;
	draw_julia(&f, f.pimg);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, &close_win, &f);
	mlx_key_hook(f.win, &key_hooks, &f);
	mlx_mouse_hook(f.win, &mouse_event, &f);
	mlx_loop(f.mlx);
}
