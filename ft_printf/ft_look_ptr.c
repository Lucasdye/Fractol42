/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:06:12 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/29 18:02:11 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_list_ptr(t_Lof *lof, t_Los *los, t_Lol *len, char *arg)
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
	los->nb = ft_strlen(arg) + 2;
	len->zero = 0;
	len->space = 0;
	len->padding = 0;
}

int	ft_look_ptr(const char *brut_data, long long int arg, char conv)
{
	t_Los	width;
	t_Lof	lof;
	t_Lol	len;
	char	*adr;
	int		count;

	if (arg == 0)
		adr = ft_strdup("(nil)");
	else
		adr = ft_dec_to_hex_lli(arg, conv);
	ft_init_list_ptr(&lof, &width, &len, adr);
	ft_flag(brut_data, &lof, conv);
	ft_width(brut_data + 1, &width, &lof);
	ft_sort_ptr(&lof, &width, adr, &len);
	if (arg != 0)
		count = len.padding + len.zero + len.space + ft_strlen(adr) + 2;
	else
		count = len.padding + len.zero + len.space + ft_strlen(adr);
	ft_print_ptr(&lof, &width, &len, adr);
	return (count);
}
