/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:37:55 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/04 19:13:45 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_ui(t_Lof *flag, t_Los *width, t_Lol *len)
{
	if (flag->precis == TRUE)
	{
		if (width->bfp > width->afp && width->bfp > width->nb)
		{
			if (width->afp > width->nb)
			{
				len->zero = width->afp - width->nb;
				len->space = width->bfp - width->afp;
			}
			else
				len->space = width->bfp - width->nb;
		}
		else if (width->afp > width->nb)
		{
			len->space = 0;
			len->zero = width->afp - width->nb;
		}
	}
	else if (width->padding != -1)
	{
		if (width->padding > width->nb)
			len->padding = width->padding - width->nb;
	}
	return ;
}
