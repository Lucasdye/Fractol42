/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:15:04 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 11:02:55 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h"

void	fractol(t_fractal *f)
{
	f->color = 0;
	f->flag = 0;
	if (f->name == JULIA)
	{
		if (init_julia(f) == WRONG)
			return ;
		julia(f);
	}
	if (f->name == MANDELBROT)
	{
		if (init_mandelbrot(f) == WRONG)
			return ;
		mandelbrot(f);
	}
	if (f->name == BURNINGSHIP)
	{
		if (init_burningship(f) == WRONG)
			return ;
		burningship(f);
	}
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if (parsing(ac, av, &f) == WRONG)
		return (0);
	f.mlx = mlx_init();
	if (!f.mlx)
		return (ft_printf("MLX ADDR ERROR (main)."), WRONG);
	fractol(&f);
	mlx_hook(f.win, MOUSEDOWN, BUTTONPRESSMASK, handle_mouse, &f);
	mlx_hook(f.win, KEYUP, KEYRELEASEMASK, handle_key, &f);
	mlx_hook(f.win, 17, 0, shutwindow, &f);
	mlx_loop(f.mlx);
}
