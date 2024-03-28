/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:14:08 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/29 12:58:00 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_count_only_digits(long long int n)
{
	int	nb;

	nb = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	while (n / 10 > 0)
	{
		nb++;
		n = n / 10;
	}
	nb++;
	return (nb);
}

int	ft_count_digits(long long int n)
{
	int	nb;

	nb = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		nb = 1;
		n = -n;
	}
	while (n / 10 > 0)
	{
		nb++;
		n = n / 10;
	}
	nb++;
	return (nb);
}

int	ft_count_args(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{	
			i++;
			if (str[i] != '%')
				return (1);
			else
				i++;
		}
		else
			i++;
	}
	return (0);
}

int	ft_spec_pos(const char *format)
{
	char	*set_conv;
	int		i;
	int		j;

	j = 0;
	i = 0;
	set_conv = strdup("iduxXscp");
	while (format[j] && format[j] != '%')
		j++;
	while (format[j])
	{
		while (set_conv[i] != '\0')
		{
			if (format[j] == set_conv[i])
				return (free(set_conv), j);
			i++;
		}
		i = 0;
		j++;
	}
	return (free(set_conv), 0);
}
