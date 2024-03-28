/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:22:39 by lbouguet          #+#    #+#             */
/*   Updated: 2023/06/27 13:43:22 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_list_ui(t_Lof *lof, t_Los *los, t_Lol *len, unsigned int arg)
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
	los->nb = ft_count_digits(arg);
	len->zero = 0;
	len->space = 0;
	len->padding = 0;
}

void	ft_init_list_ui_hexa(t_Lof *lof, t_Los *los, t_Lol *len, char *arg)
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
	los->nb = ft_strlen(arg);
	len->zero = 0;
	len->space = 0;
	len->padding = 0;
}

int	ft_look_ui_end(int c, t_lists *li, unsigned int arg)
{
	ft_sort_ui(&li->lof, &li->los, &li->lol);
	if (li->los.afp == 0 && arg == 0 && li->los.bfp == 0)
		return (0);
	ft_print_ui(&li->lof, &li->los, &li->lol, arg);
	c = li->lol.padding + li->lol.zero + li->lol.space + li->los.nb;
	return (c);
}

int	ft_look_ui_suite(int c, t_lists *li, unsigned int arg, char conv)
{
	char	*str_h;

	str_h = NULL;
	str_h = ft_dec_to_hex(arg, conv);
	if (*str_h != 48)
		li->los.nb = ft_strlen(str_h);
	ft_sort_ui_hexa(&li->lof, &li->los, str_h, &li->lol);
	if (li->lof.hashtag_maj != -1 || li->lof.hashtag_min != -1)
	{
		c = li->lol.padding + li->lol.zero + li->lol.space + li->los.nb;
		if (*str_h != '0')
			c += 2;
	}
	else
		c = li->lol.padding + li->lol.zero + li->lol.space + li->los.nb;
	if (li->los.afp == 0 && arg == 0 && li->los.bfp == 0)
		return (free(str_h), 0);
	ft_print_ui_hexa(&li->lof, &li->los, &li->lol, str_h);
	return (c);
}

int	ft_look_ui(const char *brut_data, unsigned int arg, char conv)
{
	t_lists	li;
	int		c;

	c = 0;
	ft_init_list_ui(&li.lof, &li.los, &li.lol, arg);
	ft_flag(brut_data, &li.lof, conv);
	ft_width(brut_data + 1, &li.los, &li.lof);
	if (arg == 0 && li.lof.precis != -1)
	{	
		li.los.nb = 0;
		li.los.nb_signed = 0;
	}
	if (conv == 'x' || conv == 'X')
		c = ft_look_ui_suite(c, &li, arg, conv);
	else
		c = ft_look_ui_end(c, &li, arg);
	return (c);
}
