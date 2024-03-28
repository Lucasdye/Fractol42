/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:18:31 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/04 19:13:32 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_precis_ptr(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		if (*arg != '(')
			ft_putstr("0x");
		ft_putstr_free(arg);
		ft_putlenchar(' ', len->space);
	}
	else
	{
		ft_putlenchar(' ', len->space);
		ft_putstr("0x");
		ft_putstr_free(arg);
	}
	return ;
}

void	ft_print_one_width_ptr(t_Lof *flag, t_Lol *len, char *arg)
{
	if (flag->hyphen != -1)
	{
		if (*arg != '(')
			ft_putstr("0x");
		ft_putstr_free(arg);
		ft_putlenchar(' ', len->padding);
	}
	else
	{
		ft_putlenchar(' ', len->padding);
		if (*arg != '(')
			ft_putstr("0x");
		ft_putstr_free(arg);
	}
	return ;
}

void	ft_print_p(char *arg)
{
	if (*arg != '(')
		ft_putstr("0x");
	ft_putstr_free(arg);
}

void	ft_print_ptr(t_Lof *flag, t_Los *width, t_Lol *len, char *arg)
{
	if (flag->precis != -1)
		ft_print_precis_ptr(flag, len, arg);
	else if (width->padding != -1)
		ft_print_one_width_ptr(flag, len, arg);
	else
		ft_print_p(arg);
}
