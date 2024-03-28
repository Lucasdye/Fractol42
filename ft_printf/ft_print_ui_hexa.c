/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ui_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:22:46 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/04 18:55:38 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putox(t_Lof *flag, char *arg)
{
	if ((flag->hashtag_min != -1 || flag->hashtag_maj != -1) && *arg != '0')
	{
		if (flag->hashtag_min != -1)
			ft_putstr("0x");
		else if (flag->hashtag_maj != -1)
			ft_putstr("0X");
		return ;
	}
	return ;
}

void	ft_print_precis_ui_hexa(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		ft_putox(flag, arg);
		ft_putlenchar('0', len->zero);
		if (*arg != 48 && len->space != -1)
			ft_putstr_free(arg);
		else
			free(arg);
		ft_putlenchar(' ', len->space);
	}
	else
	{
		ft_putlenchar(' ', len->space);
		ft_putox(flag, arg);
		ft_putlenchar('0', len->zero);
		if (*arg != 48 && len->space != -1)
			ft_putstr_free(arg);
		else
			free(arg);
	}
	return ;
}

void	ft_print_one_width_ui_hexa(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		ft_putox(flag, arg);
		ft_putstr_free(arg);
		ft_putlenchar(' ', len->padding);
	}
	else if (flag->zero != -1)
	{
		ft_putox(flag, arg);
		ft_putlenchar('0', len->padding);
		ft_putstr_free(arg);
	}
	else
	{
		ft_putlenchar(' ', len->padding);
		ft_putox(flag, arg);
		ft_putstr_free(arg);
	}
	return ;
}

void	ft_print_uh(t_Lof *flag, char *arg)
{
	ft_putox(flag, arg);
	ft_putstr_free(arg);
	return ;
}

void	ft_print_ui_hexa(t_Lof *flag, t_Los *width, t_Lol *len, char *arg)
{
	if (flag->precis != -1)
		ft_print_precis_ui_hexa(flag, len, arg);
	else if (width->padding != -1)
		ft_print_one_width_ui_hexa(flag, len, arg);
	else
	{
		ft_putox(flag, arg);
		ft_putstr_free(arg);
	}
	return ;
}
