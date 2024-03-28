/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:02:41 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 17:08:34 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h"

void	handle_mouse_wheel(int button, int x, int y, t_fractal *f)
{
	f->zm.zoom_factor = 1.25;
	if (button == WHEELDOWN)
	{
		f->zm.new_zoom = f->zoom * f->zm.zoom_factor;
		f->zm.zoom_offset_x = (x / f->zm.prev_zoom) - (x / f->zm.new_zoom);
		f->zm.zoom_offset_y = (y / f->zm.prev_zoom) - (y / f->zm.new_zoom);
		f->zoom = f->zm.new_zoom;
		f->x1 = f->zm.prev_x1 + f->zm.zoom_offset_x;
		f->y1 = f->zm.prev_y1 + f->zm.zoom_offset_y;
	}
	else if (button == WHEELUP)
	{
		f->zm.new_zoom = f->zoom / f->zm.zoom_factor;
		f->zm.zoom_offset_x = (x / f->zm.prev_zoom) - (x / f->zm.new_zoom);
		f->zm.zoom_offset_y = (y / f->zm.prev_zoom) - (y / f->zm.new_zoom);
		f->zoom = f->zm.new_zoom;
		f->x1 = f->zm.prev_x1 + f->zm.zoom_offset_x;
		f->y1 = f->zm.prev_y1 + f->zm.zoom_offset_y;
	}
}

void	init_handle_mouse(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	mlx_destroy_image(f->mlx, f->im.img);
	f->flag = 1;
	f->zm.prev_x1 = f->x1;
	f->zm.prev_y1 = f->y1;
	f->zm.prev_zoom = f->zoom;
	f->im.img = mlx_new_image(f->mlx, f->x_im, f->y_im);
	f->im.addr = mlx_get_data_addr(f->im.img, &f->im.bpp,
			&f->im.size_line, &f->im.endian);
}

int	handle_mouse(int button, int x, int y, t_fractal *f)
{
	init_handle_mouse(f);
	handle_mouse_wheel(button, x, y, f);
	if (f->name == JULIA)
		julia(f);
	else if (f->name == MANDELBROT)
		mandelbrot(f);
	else if (f->name == BURNINGSHIP)
		burningship(f);
	return (button);
}

int	shutwindow(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->im.img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
	return (CORRECT);
}
