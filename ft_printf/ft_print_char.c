/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:27:04 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/22 15:02:28 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_precis_char(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		ft_putlenchar('0', len->zero);
		ft_putchar(*arg);
		ft_putlenchar(' ', len->space);
	}
	else
	{
		ft_putlenchar(' ', len->space);
		ft_putlenchar('0', len->zero);
		ft_putchar(*arg);
	}
	return ;
}

void	ft_print_one_width_char(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		ft_putchar(*arg);
		ft_putlenchar(' ', len->padding);
	}
	else if (flag->zero != -1)
	{
		ft_putlenchar('0', len->padding);
		ft_putchar(*arg);
	}
	else
	{
		ft_putlenchar(' ', len->padding);
		ft_putchar(*arg);
	}
	return ;
}

void	ft_print_char(t_Lof *flag, t_Los *width, t_Lol *len, char *arg)
{
	if (flag->precis != -1)
		ft_print_precis_char(flag, len, arg);
	else if (width->padding != -1)
		ft_print_one_width_char(flag, len, arg);
	else
		ft_putchar(*arg);
}
