/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/25 15:26:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Close windows
int	close_win(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->win);
	f->win = NULL;
	exit(0);
}

int	key_hooks(int keycode, t_fractol *f)
{
	if (keycode == 53)
		close_win(f);
	return (0);
}

// Mouse Zooming
static void	move(t_fractol *f, double distance, char direction)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += range_r * distance;
		f->max_r += range_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= range_r * distance;
		f->max_r -= range_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= range_i * distance;
		f->max_i -= range_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += range_i * distance;
		f->max_i += range_i * distance;
	}
}

static void	zoom(t_fractol *f, double zoom)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	f->max_r = f->max_r - (range_r - zoom * range_r) / 2;
	f->min_r = f->max_r - zoom * range_r;
	f->min_i = f->min_i + (range_i - zoom * range_i) / 2;
	f->max_i = f->min_i + zoom * range_i;
}

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(f, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(f, (double)x / WIDTH, 'R');
		if (y < 0)
			move(f, (double)y * -1 / HEIGHT, 'D');
		else if (y > 0)
			move(f, (double)y / HEIGHT, 'U');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(f, 2);
	else
		return (0);
	if (!ft_strncmp(f->f_name, "mandelbrot", 11))
		draw_mandelbrot(f, f->pimg);
	if (!ft_strncmp(f->f_name, "julia", 6))
		draw_julia(f, f->pimg);
	return (0);
}
