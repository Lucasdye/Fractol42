/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:19 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/12 18:22:10 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_str(t_Lof *flag, t_Los *width, char *arg, t_Lol *len)
{
	if (arg && flag->precis != -1 && *arg == '(')
	{	
		if (flag->precis != -1 && width->afp < 6)
		{
			*arg = '\0';
			width->nb = 0;
			width->nb_signed = 0;
			len->space = width->bfp;
		}
	}
	else if (flag->precis != -1)
	{
		if (arg && width->afp < width->nb)
			arg[width->afp] = '\0';
		if (width->bfp > (int)ft_strlen(arg))
			len->space = width->bfp - (int)ft_strlen(arg);
		else
			len->space = 0;
	}
	else if (width->padding != -1 && width->padding > (int)ft_strlen(arg))
	{
		len->padding = width->padding - (int)ft_strlen(arg);
	}
	return ;
}
