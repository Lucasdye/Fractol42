/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:36:59 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 11:02:51 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h" 

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

unsigned int	color(int iteration, t_fractal *f)
{
	f->c.red = 0;
	f->c.green = 0;
	f->c.blue = 0;
	f->c.op = 0;
	f->c.r = 0.0f;
	f->c.g = 0.0f;
	f->c.b = 0.0f;
	if (f->color == 0)
		return (render_color(iteration, f));
	if (f->color == 1)
		return (render_color2(iteration, f));
	if (f->color == 2)
		return (render_color3(iteration, f));
	return (0);
}

unsigned int	render_color2(int iteration, t_fractal *f)
{
	if (iteration == f->iter_max)
		return (0);
	f->c.op = 0;
	f->c.red = 30 + iteration;
	f->c.green = 30 + iteration;
	f->c.blue = 30 + iteration;
	return ((f->c.op << 24) | (f->c.red << 16) | (f->c.green << 8) | f->c.blue);
}

unsigned int	render_color3(int iteration, t_fractal *f)
{
	int	color_idx;

	color_idx = iteration % 8;
	if (iteration == f->iter_max)
		return (0);
	if (color_idx == 0)
		f->c.red = 255;
	else if (color_idx == 1)
		orange(f);
	else if (color_idx == 2)
		yellow(f);
	else if (color_idx == 3)
		violet(f);
	else if (color_idx == 4)
		thistle(f);
	else if (color_idx == 5)
		f->c.blue = 255;
	else if (color_idx == 6)
		f->c.blue = 139;
	return ((f->c.op << 24) | (f->c.red << 8) | (f->c.green << 16) | f->c.blue);
}

unsigned int	render_color(int iteration, t_fractal *f)
{
	int	color_idx;

	color_idx = iteration % 8;
	if (iteration == f->iter_max)
		return (0);
	if (color_idx == 0)
		f->c.red = 255;
	else if (color_idx == 1)
		orange(f);
	else if (color_idx == 2)
		yellow(f);
	else if (color_idx == 3)
		violet(f);
	else if (color_idx == 4)
		thistle(f);
	else if (color_idx == 5)
		f->c.blue = 255;
	else if (color_idx == 6)
		f->c.blue = 139;
	return ((f->c.op << 24) | (f->c.red << 16) | (f->c.green << 8) | f->c.blue);
}
