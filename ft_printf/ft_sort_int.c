/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:39:09 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/14 15:27:01 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_precis(t_Lof *flag, t_Los *w, t_Lol *len, int arg)
{
	if (w->bfp > w->afp && w->bfp > w->nb)
	{
		if (w->afp > w->nb)
		{
			len->zero = w->afp - w->nb;
			if (arg > 0 && (flag->plus != -1 || flag->space != -1))
				len->space = w->bfp - (w->afp + (w->nb_signed - w->nb)) - 1;
			else
				len->space = w->bfp - (w->afp + (w->nb_signed - w->nb));
		}
		else if (arg > 0 && (flag->plus != -1 || flag->space != -1))
			len->space = w->bfp - w->nb_signed - 1;
		else
			len->space = w->bfp - w->nb_signed;
	}
	else if (w->afp > w->nb)
	{
		len->space = 0;
		len->zero = w->afp - w->nb;
	}
	return ;
}

void	ft_sort_int(t_Lof *flag, t_Los *w, t_Lol *len, int arg)
{
	if (flag->precis == TRUE)
		ft_sort_precis(flag, w, len, arg);
	else if (w->padding != TRUE)
	{
		if (w->padding > w->nb)
		{
			if (arg > 0 && (flag->plus != -1 || flag->space != -1))
				len->padding = w->padding - w->nb_signed - 1;
			else
				len->padding = w->padding - w->nb_signed;
		}
	}
	return ;
}
