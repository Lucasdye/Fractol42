/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:46:17 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 11:03:11 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h"

int	init_win_and_img(t_fractal *f)
{
	if (f->flag == 0)
	{	
		f->win = mlx_new_window(f->mlx, f->win_width,
				f->win_height, "fract-ol");
		if (!f->win)
			return (ft_printf("WIN ADDR ERROR."), WRONG);
		f->im.img = mlx_new_image(f->mlx, f->x_im, f->y_im);
		if (!f->im.img)
			return (WRONG);
		f->im.addr = mlx_get_data_addr(f->im.img, &f->im.bpp,
				&f->im.size_line, &f->im.endian);
		if (!f->im.addr)
			return (ft_printf("IMG ADDR ERROR"), WRONG);
	}
	return (CORRECT);
}

int	init_julia(t_fractal *f)
{	
	f->idx = 0;
	f->y = 0;
	f->x = 0;
	f->iter_max = 100;
	f->scale_im = 200;
	f->zoom = 200;
	f->win_width = 800;
	f->win_height = 480;
	f->x1 = -2.0;
	f->x2 = 2;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->x_im = (f->x2 - f->x1) * f->scale_im;
	f->y_im = (f->y2 - f->y1) * f->scale_im;
	julia_var(f);
	init_win_and_img(f);
	return (CORRECT);
}

void	julia_var(t_fractal *f)
{
	if (f->variant == 'n')
	{
		f->cr = -1.28;
		f->ci = -0.35;
	}
	if (f->variant == 'b')
	{
		f->cr = 0.258;
		f->ci = 0.0;
	}	
	if (f->variant == 'g')
	{
		f->cr = -0.70176;
		f->ci = -0.3842;
	}
	f->zr = 0;
	f->zi = 0;
}

int	init_mandelbrot(t_fractal *f)
{	
	f->idx = 0;
	f->y = 0;
	f->x = 0;
	f->iter_max = 100;
	f->scale_im = 200;
	f->zoom = 200;
	f->win_width = 800;
	f->win_height = 480;
	f->x1 = -2.0;
	f->x2 = 2;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->x_im = (f->x2 - f->x1) * f->scale_im;
	f->y_im = (f->y2 - f->y1) * f->scale_im;
	init_win_and_img(f);
	return (CORRECT);
}

int	init_burningship(t_fractal *f)
{	
	f->idx = 0;
	f->y = 0;
	f->x = 0;
	f->iter_max = 100;
	f->scale_im = 200;
	f->zoom = 200;
	f->win_width = 800;
	f->win_height = 520;
	f->x1 = -2.5;
	f->x2 = 1.5;
	f->y1 = -2.0;
	f->y2 = 2.0;
	f->x_im = (f->x2 - f->x1) * f->scale_im;
	f->y_im = (f->y2 - f->y1) * f->scale_im;
	init_win_and_img(f);
	return (CORRECT);
}
