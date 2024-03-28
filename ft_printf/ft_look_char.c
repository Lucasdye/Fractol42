/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:25:23 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/27 13:41:59 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_list_char(t_Lof *lof, t_Los *los, t_Lol *len)
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
	los->nb = 1;
	len->zero = 0;
	len->space = 0;
	len->padding = 0;
}

int	ft_look_char(const char *brut_data, char *arg, char conv)
{
	t_Los	width;
	t_Lof	lof;
	t_Lol	len;
	int		count;

	count = 0;
	ft_initialise_list_char(&lof, &width, &len);
	ft_flag(brut_data, &lof, conv);
	ft_width(brut_data + 1, &width, &lof);
	ft_sort_char(&lof, &width, arg, &len);
	ft_print_char(&lof, &width, &len, arg);
	count = len.padding + len.zero + len.space + 1;
	return (count);
}
