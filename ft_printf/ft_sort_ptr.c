/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:59 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/29 18:05:45 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_ptr(t_Lof *flag, t_Los *width, char *arg, t_Lol *len)
{
	if (flag->precis != -1)
	{
		if (width->bfp > width->nb)
			len->space = (width->bfp - width->nb) - 2;
		else
			len->space = 0;
	}
	else if (width->padding != -1 && width->padding > width->nb)
	{
		if (*arg != '(')
			len->padding = width->padding - (int)ft_strlen(arg) - 2;
		else
			len->padding = width->padding - (int)ft_strlen(arg);
	}
	return ;
}
