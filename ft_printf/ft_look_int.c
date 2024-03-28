/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:49:28 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/14 15:33:46 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_list_int(t_Lof *lof, t_Los *los, t_Lol *len, int arg)
{
	lof->plus = -1;
	lof->zero = -1;
	lof->precis = -1;
	lof->space = -1;
	lof->hyphen = -1;
	lof->hashtag_min = -1;
	lof->hashtag_maj = -1;
	los->bfp = -1;
	los->afp = -1;
	los->padding = -1;
	los->nb = ft_count_only_digits(arg);
	los->nb_signed = ft_count_digits(arg);
	len->zero = 0;
	len->space = 0;
	len->padding = 0;
}

int	ft_look_int(const char *brut_data, int a)
{
	t_Los	width;
	t_Lof	lof;
	t_Lol	len;
	int		count;

	count = 0;
	ft_initialise_list_int(&lof, &width, &len, a);
	ft_flag(brut_data, &lof, 'd');
	ft_width(brut_data + 1, &width, &lof);
	if (a == 0 && lof.precis != -1)
	{	
		width.nb = 0;
		width.nb_signed = 0;
	}
	ft_sort_int(&lof, &width, &len, a);
	ft_print_int(&lof, &width, &len, a);
	if (a == 0 && lof.precis != -1)
		count = len.padding + len.zero + len.space + 0;
	else
		count = len.padding + len.zero + len.space + width.nb;
	if ((lof.space != -1 && a >= 0) || (lof.plus != -1 && a >= 0) || a < 0)
		count++;
	return (count);
}
