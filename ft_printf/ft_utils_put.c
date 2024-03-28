/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:18:15 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/29 14:51:10 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char a)
{
	int	test;

	test = write(1, &a, 1);
	return (test);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
	return ;
}

void	ft_putstr_free(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
	return (free(str));
}

int	ft_putformat(const char *str, int global_count)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] == '\\')
		{	
			i++;
			write(1, "\\", 1);
			global_count++;
		}
		else if (str[i] == '%')
		{	
			i++;
			write(1, "%", 1);
			global_count++;
		}
		else
			global_count++;
		if (str[i] != '%' && str[i] != '\\')
			write(1, &str[i], 1);
		i++;
	}
	return (global_count);
}

void	ft_putlenchar(const char to_print, int len)
{
	while (len)
	{
		write(1, &to_print, 1);
		len--;
	}
	return ;
}
