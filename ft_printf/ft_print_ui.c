/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:24:08 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/29 19:13:21 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_precis_ui(t_Lof *flag, t_Lol *len, unsigned int arg)
{
	if (flag->hyphen != -1)
	{
		ft_putlenchar('0', len->zero);
		if (arg != 0)
			ft_putstr_free(ft_itoa_ui(arg));
		ft_putlenchar(' ', len->space);
	}
	else
	{
		ft_putlenchar(' ', len->space);
		ft_putlenchar('0', len->zero);
		if (arg != 0)
			ft_putstr_free(ft_itoa_ui(arg));
	}
	return ;
}

void	ft_print_one_width_ui(t_Lof *flag, t_Lol *len, unsigned int arg)
{
	if (flag->hyphen != -1)
	{
		ft_putstr_free(ft_itoa_ui(arg));
		ft_putlenchar(' ', len->padding);
	}
	else if (flag->zero != -1)
	{
		ft_putlenchar('0', len->padding);
		ft_putstr_free(ft_itoa_ui(arg));
	}
	else
	{
		ft_putlenchar(' ', len->padding);
		ft_putstr_free(ft_itoa_ui(arg));
	}
	return ;
}

void	ft_print_ui(t_Lof *flag, t_Los *width, t_Lol *len, unsigned int arg)
{
	if (flag->precis != -1)
		ft_print_precis_ui(flag, len, arg);
	else if (width->padding != -1)
		ft_print_one_width_ui(flag, len, arg);
	else
		ft_putstr_free(ft_itoa(arg));
}
