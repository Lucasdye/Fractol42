/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:02:57 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/22 14:38:03 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_char(t_Lof *flag, t_Los *width, char *arg, t_Lol *len)
{
	if (flag->precis != -1)
	{
		if (width->bfp <= width->afp)
		{
			len->space = 0;
			if (width->afp > (int)ft_strlen(arg))
				len->zero = width->afp - (ft_strlen(arg));
			else
				len->zero = 0;
		}
		else if ((width->afp) > (int)ft_strlen(arg))
		{
			len->space = (width->bfp - (width->afp));
			len->zero = width->afp - (int)ft_strlen(arg);
		}
		else
			len->space = width->bfp - 1;
	}
	else if (width->padding != -1 && width->padding > 1)
		len->padding = width->padding - 1;
	return ;
}
