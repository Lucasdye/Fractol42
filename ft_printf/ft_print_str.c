/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:21:03 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/12 14:37:06 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_precis_str(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		ft_putstr(arg);
		ft_putlenchar(' ', len->space);
	}
	else
	{
		ft_putlenchar(' ', len->space);
		ft_putstr(arg);
	}
	return ;
}

void	ft_print_one_width_str(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		ft_putstr(arg);
		ft_putlenchar(' ', len->padding);
	}
	else
	{
		ft_putlenchar(' ', len->padding);
		ft_putstr(arg);
	}
	return ;
}

void	ft_print_str(t_Lof *flag, t_Los *width, t_Lol *len, char *arg)
{
	if (flag->precis != -1)
		ft_print_precis_str(flag, len, arg);
	else if (width->padding != -1)
		ft_print_one_width_str(flag, len, arg);
	else
		ft_putstr(arg);
}
