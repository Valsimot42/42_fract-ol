/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/05 10:44:31 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Close windows

/* Initialization of mlx_destroy_window from mlx library,
which as the name suggests, destroys the window. However, 
to cleanly exit the program, we must not forget the exit() function. */
int	close_win(t_fractol *f)
{
	mlx_destroy_window(f->mlx, f->mlx_win);
	f->mlx_win = NULL;
	exit(0);
}

/* Upon pressing the ESC buton on keyboard, whose keycode is 53,
key_hooks function will call close_win function which will kill
the window upon pressing ESC button. */
int	key_hooks(int keycode, t_fractol *f)
{
	if (keycode == 53)
		close_win(f);
	return (0);
}

// Mouse Zooming

/* With function move, we are able to precisely zoom in specified direction,
depending on our result from the code below. Depending on the position of our
mouse, we can either zoom in left, right, down or up. */
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

/* With the following function zoom, we are able to assign new ranges
to our previously existing range values. */
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

/* In our mouse_event function, we have two events that can happen,
either we zoom in or out, and depending on the action taken, we will
execute the relevant if statement. */
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
		zoom(f, 1.5);
	else
		return (0);
	if (!ft_strncmp(f->f_name, "mandelbrot", 11))
		draw_mandelbrot(f, f->pimg);
	if (!ft_strncmp(f->f_name, "julia", 6))
		draw_julia(f, f->pimg);
	return (0);
}
