/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:53:39 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 17:12:00 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h"

void	restart(int button, t_fractal *f)
{
	f->idx = 0;
	f->x = 0;
	f->y = 0;
	if (button == TAB)
	{
		f->flag = 1;
		if (f->name == JULIA)
			init_julia(f);
		if (f->name == MANDELBROT)
			init_mandelbrot(f);
		if (f->name == BURNINGSHIP)
			init_burningship(f);
	}
}

void	shutting_down(int button, t_fractal *f)
{
	if (button == ESC)
	{
		mlx_destroy_image(f->mlx, f->im.img);
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
		exit(0);
	}
}

void	change_color(int button, t_fractal *f)
{
	if (button == SPACE)
	{
		if (f->color < 2)
			f->color++;
		else
			f->color = 0;
	}
}

void	increase_decrease_complex_number_and_arrows(int button, t_fractal *f)
{
	if (button == RIGHT)
		f->x1 += 0.05;
	if (button == LEFT)
		f->x1 -= 0.05;
	if (button == UP)
		f->y1 -= 0.05;
	if (button == DOWN)
		f->y1 += 0.05;
	if (button == REALINCR)
		f->cr += 0.01;
	if (button == REALDECR)
		f->cr -= 0.01;
	if (button == IMAINCR)
		f->ci += 0.01;
	if (button == IMADECR)
		f->ci -= 0.01;
}

int	handle_key(int button, t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->im.img);
	f->im.img = mlx_new_image(f->mlx, f->x_im, f->y_im);
	if (!f->im.img)
		return (ft_printf("init img error\n"), WRONG);
	f->im.addr = mlx_get_data_addr(f->im.img, &f->im.bpp,
			&f->im.size_line, &f->im.endian);
	if (!f->im.addr)
		return (ft_printf("get img addr error\n"), WRONG);
	increase_decrease_complex_number_and_arrows(button, f);
	change_color(button, f);
	shutting_down(button, f);
	restart(button, f);
	if (f->name == JULIA)
		julia(f);
	else if (f->name == MANDELBROT)
		mandelbrot(f);
	else if (f->name == BURNINGSHIP)
		burningship(f);
	return (CORRECT);
}
