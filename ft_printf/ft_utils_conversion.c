/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:30 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/28 18:09:32 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*ft_itoa(int n)
// {
// 	long long int	nb;
// 	char			*res;
// 	int				i;
// 	int				end;

// 	end = 0;
// 	nb = n;
// 	i = ft_count_digits(nb);
// 	res = malloc(sizeof(char) * (i + 1));
// 	if (!res)
// 		return (0);
// 	if (nb < 0)
// 	{
// 		res[0] = '-';
// 		nb = -nb;
// 		end = 1;
// 	}
// 	res[i] = '\0';
// 	while (i-- > end)
// 	{
// 		res[i] = nb % 10 + 48;
// 		nb = nb / 10;
// 	}
// 	return (res);
// }

char	*ft_itoa_unsigned(int n)
{
	char	*res;
	int		i;
	int		end;
	long	nb;

	end = 0;
	nb = n;
	i = ft_count_only_digits(nb);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	if (nb < 0)
		nb = -nb;
	res[i] = '\0';
	while (i-- > end)
	{
		res[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}

char	*ft_llitoa(long long int n)
{
	char			*res;
	int				i;
	int				end;
	long long int	nb;

	end = 0;
	nb = n;
	i = ft_count_digits(nb);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
		end = 1;
	}
	res[i] = '\0';
	while (i-- > end)
	{
		res[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	n;
// 	int	sign;

// 	i = 0;
// 	n = 0;
// 	sign = 1;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{	
// 		if (str[i] == '-')
// 			sign = sign * (-1);
// 		i++;
// 	}
// 	while (str[i] >= 48 && str[i] <= 57)
// 	{		
// 		n = n * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	return (n * sign);
// }

char	*ft_itoa_ui(unsigned int n)
{
	char	*res;
	int		i;
	int		end;
	long	nb;

	end = 0;
	nb = n;
	i = ft_count_only_digits(nb);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	res[i] = '\0';
	while (i-- > end)
	{
		res[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (res);
}
