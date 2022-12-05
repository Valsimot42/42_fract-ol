/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:54:46 by stena-he          #+#    #+#             */
/*   Updated: 2022/12/05 11:16:24 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	atod_loop(char *arr, int afterdot, float scale, float *val)
{
	while (*arr)
	{
		if (!ft_isdigit(*arr) && !(*arr == '.'))
		{
			ft_printf("You done fucked up.\n\n");
			print_help();
			exit(0);
		}
		if (afterdot)
		{
			scale = scale / 10;
			*val = *val + (*arr - '0') * scale;
		}
		else
		{
			if (*arr == '.')
				afterdot++;
			else
				*val = *val * 10.0 + (*arr - '0');
		}
		arr++;
	}	
}

double	ft_atod(char *arr)
{
	float	val;
	int		afterdot;
	float	scale;
	int		neg;

	val = 0;
	afterdot = 0;
	scale = 1;
	neg = 0;
	if (*arr == '-')
	{
		arr++;
		neg = 1;
	}
	atod_loop(arr, afterdot, scale, &val);
	if (neg)
		return (-val);
	else
		return (val);
}

int	bernstein_color(int n)
{
	double	r;
	double	g;
	double	b;
	double	t;
	double	color;

	t = (double)n / 255;
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * pow((1 - t), 2) * t * t * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	color = 0 << 24 | (int)r << 16 | (int)g << 8 | (int)b;
	return (color);
}
