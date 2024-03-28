/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:16:08 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/13 16:32:52 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsign_int(t_Lof *flag, int arg)
{
	if (flag->plus != -1 && arg >= 0)
		ft_putchar('+');
	else if (flag->space != -1 && arg >= 0)
		ft_putchar(' ');
	else if (arg < 0)
		ft_putchar('-');
	return ;
}

void	ft_print_precis_int(t_Lof *flag, t_Lol *len, int arg)
{
	if (flag->hyphen != -1)
	{
		ft_putsign_int(flag, arg);
		ft_putlenchar('0', len->zero);
		if (arg != 0)
			ft_putstr_free(ft_itoa_unsigned(arg));
		ft_putlenchar(' ', len->space);
	}
	else
	{
		ft_putlenchar(' ', len->space);
		ft_putsign_int(flag, arg);
		ft_putlenchar('0', len->zero);
		if (arg != 0)
			ft_putstr_free(ft_itoa_unsigned(arg));
	}
	return ;
}

void	ft_print_one_width_int(t_Lof *flag, t_Lol *len, int arg)
{
	if (flag->hyphen != -1)
	{
		ft_putsign_int(flag, arg);
		ft_putstr_free(ft_itoa_unsigned(arg));
		ft_putlenchar(' ', len->padding);
	}
	else if (flag->zero != -1)
	{
		ft_putsign_int(flag, arg);
		ft_putlenchar('0', len->padding);
		ft_putstr_free(ft_itoa_unsigned(arg));
	}
	else
	{
		ft_putlenchar(' ', len->padding);
		ft_putsign_int(flag, arg);
		ft_putstr_free(ft_itoa_unsigned(arg));
	}
	return ;
}

void	ft_print_i(t_Lof *flag, int arg)
{
	ft_putsign_int(flag, arg);
	ft_putstr_free(ft_itoa_unsigned(arg));
}

void	ft_print_int(t_Lof *flag, t_Los *width, t_Lol *len, int arg)
{
	if (flag->precis != -1)
		ft_print_precis_int(flag, len, arg);
	else if (width->padding != -1)
		ft_print_one_width_int(flag, len, arg);
	else
		ft_print_i(flag, arg);
}
