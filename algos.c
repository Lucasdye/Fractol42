/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:03:01 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 11:02:45 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h"

void	formula(t_fractal *f)
{
	f->tempr = f->zr;
	f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
	f->zi = (f->zi * f->tempr) + (f->tempr * f->zi) + f->ci;
	f->idx++;
}

void	reinit_loop(t_fractal *f)
{
	if (f->name == MANDELBROT || f->name == BURNINGSHIP)
	{	
		f->idx = 0;
		f->zr = 0;
		f->zi = 0;
		f->cr = (f->x / f->zoom) + f->x1;
		f->ci = (f->y / f->zoom) + f->y1;
	}
	else if (f->name == JULIA)
	{
		f->idx = 0;
		f->zr = (f->x / f->zoom) + f->x1;
		f->zi = (f->y / f->zoom) + f->y1;
	}
}

int	julia(t_fractal *f)
{
	while (f->x < f->x_im)
	{
		while (f->y < f->y_im)
		{
			reinit_loop(f);
			while ((f->zr * f->zr) + (f->zi * f->zi) < 4
				&& f->idx < f->iter_max)
				formula(f);
			if (f->idx == f->iter_max)
				img_pix_put(&f->im, f->x, f->y, 0);
			else
				img_pix_put(&f->im, f->x, f->y, color(f->idx, f));
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->im.img, 0, 0);
	return (0);
}

void	mandelbrot(t_fractal *f)
{
	while (f->x < f->x_im)
	{
		while (f->y < f->y_im)
		{
			reinit_loop(f);
			f->idx = 0;
			while ((f->zr * f->zr) + (f->zi * f->zi) < 4
				&& f->idx < f->iter_max)
				formula(f);
			if (f->idx == f->iter_max)
				img_pix_put(&f->im, f->x, f->y, 0);
			else
				img_pix_put(&f->im, f->x, f->y, color(f->idx, f));
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->im.img, 0, 0);
}

void	burningship(t_fractal *f)
{
	while (f->x < f->x_im)
	{
		while (f->y < f->y_im)
		{
			reinit_loop(f);
			while ((f->zr * f->zr) + (f->zi * f->zi) < 4
				&& f->idx < f->iter_max)
			{
				f->tempr = f->zr;
				f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
				f->zi = fabs(2 * f->tempr * f->zi) + f->ci;
				f->idx++;
			}
			if (f->idx == f->iter_max)
				img_pix_put(&f->im, f->x, f->y, 0);
			else
				img_pix_put(&f->im, f->x, f->y, color(f->idx, f));
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->im.img, 0, 0);
}
