/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:29:48 by lbouguet          #+#    #+#             */
/*   Updated: 2023/07/17 11:03:19 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol_linux.h"

int	parsing(int ac, char **av, t_fractal *f)
{
	if (ac < 3 && ac != 2)
		return (ft_printf(ERROR_MSG1), WRONG);
	if (ft_strncmp("Julia", av[1], 6) != CORRECT
		&& ft_strncmp("Mandelbrot", av[1], 11) != CORRECT
		&& ft_strncmp("BurningShip", av[1], 12) != CORRECT)
		return (ft_printf(ERROR_MSG2), WRONG);
	else if (av[1][0] == 'J')
	{
		if (!av[2] || (ft_strncmp("neuron", av[2], 7) != CORRECT
				&& ft_strncmp("galaxy", av[2], 7) != CORRECT
				&& ft_strncmp("brain", av[2], 7) != CORRECT))
			return (ft_printf(ERROR_MSG3), WRONG);
	}
	else if (av[1][0] == 'M' || av[1][0] == 'B')
	{
		if (av[2])
			return (ft_printf(ERROR_MSG4), WRONG);
	}
	user_input(f, av);
	return (CORRECT);
}

void	user_input(t_fractal *f, char **av)
{
	if (av[1][0] == 'J')
	{	
		f->name = JULIA;
		if (av[2][0] == 'n')
			f->variant = 'n';
		if (av[2][0] == 'b')
			f->variant = 'b';
		if (av[2][0] == 'g')
			f->variant = 'g';
	}
	if (av[1][0] == 'M')
		f->name = MANDELBROT;
	if (av[1][0] == 'B')
		f->name = BURNINGSHIP;
	return ;
}
