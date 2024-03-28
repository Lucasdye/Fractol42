/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:51:29 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 11:03:15 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h" 

void	orange(t_fractal *f)
{
	f->c.red = 255;
	f->c.green = 165;
}

void	yellow(t_fractal *f)
{	
	f->c.red = 255;
	f->c.green = 255;
	f->c.blue = 0;
}

void	violet(t_fractal *f)
{
	f->c.red = 238;
	f->c.green = 130;
	f->c.blue = 238;
}

void	thistle(t_fractal *f)
{
	f->c.red = 216;
	f->c.green = 191;
	f->c.blue = 216;
}
