/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ui_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:08 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/04 18:09:06 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_ui_hexa_padd(t_Lof *flag, t_Los *width, char *arg, t_Lol *len)
{
	(void)arg;
	if ((flag->hashtag_maj != -1 || flag->hashtag_min != -1)
		&& width->padding > width->nb + 2)
		len->padding = width->padding - (width->nb + 2);
	else if (flag->hashtag_maj != -1 || flag->hashtag_min != -1)
		len->padding = 0;
	else
			len->padding = width->padding - width->nb;
	return ;
}

void	ft_sort_ui_hexa(t_Lof *flag, t_Los *width, char *arg, t_Lol *len)
{
	if (flag->precis != -1)
	{
		if (width->bfp <= width->afp)
		{
			len->space = 0;
			if (width->afp > width->nb)
				len->zero = width->afp - (width->nb);
			else
				len->zero = 0;
		}
		else if ((width->afp) > width->nb)
		{
			if (flag->hashtag_min != -1 || flag->hashtag_maj != -1)
				len->space = (width->bfp - (width->afp) - 2);
			else
				len->space = (width->bfp - (width->afp));
			len->zero = width->afp - width->nb;
		}
		else if (width->bfp > width->nb)
			len->space = width->bfp - width->nb;
	}
	else if (width->padding != -1 && width->padding > width->nb)
		ft_sort_ui_hexa_padd(flag, width, arg, len);
	return ;
}
