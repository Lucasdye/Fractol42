/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_conversion_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:11:47 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/28 18:10:30 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dec_to_hex_lli(long long int dec, char conv)
{
	int		i;
	int		mod;
	char	*str_nb;

	if (dec == LONG_MIN)
		return (str_nb = ft_strdup("8000000000000000"));
	str_nb = malloc(1000);
	if (!str_nb)
		return (NULL);
	i = 0;
	while (dec != 0 || (dec == 0 && i == 0))
	{	
		mod = dec % 16;
		if (conv == 'x')
			str_nb[i] = ft_itoa_hexa_min(mod);
		else if (conv == 'X')
			str_nb[i] = ft_itoa_hexa_maj(mod);
		else
			str_nb[i] = ft_itoa_hexa_min(mod);
		dec = dec / 16;
		i++;
	}
	str_nb[i] = '\0';
	ft_str_reverse(str_nb);
	return (str_nb);
}

char	*ft_dec_to_hex_ulli(unsigned long long int dec, char conv)
{
	int		i;
	int		mod;
	char	*str_nb;

	if (dec == 0)
		return (str_nb = ft_strdup("0"));
	str_nb = malloc(1000);
	if (!str_nb)
		return (NULL);
	i = 0;
	while (dec != 0 || (dec == 0 && i == 0))
	{	
		mod = dec % 16;
		if (conv == 'x')
			str_nb[i] = ft_itoa_hexa_min(mod);
		else if (conv == 'X')
			str_nb[i] = ft_itoa_hexa_maj(mod);
		else
			str_nb[i] = ft_itoa_hexa_min(mod);
		dec = dec / 16;
		i++;
	}
	str_nb[i] = '\0';
	ft_str_reverse(str_nb);
	return (str_nb);
}

char	ft_itoa_hexa_maj(unsigned int n)
{
	if (n < 0)
		n = n * (-1);
	if (n >= 10)
	{	
		if (n == 10)
			return ('A');
		if (n == 11)
			return ('B');
		if (n == 12)
			return ('C');
		if (n == 13)
			return ('D');
		if (n == 14)
			return ('E');
		if (n == 15)
			return ('F');
	}
	else if (n < 10 && n >= 0)
		return (n + '0');
	return ('0');
}	

char	ft_itoa_hexa_min(unsigned int n)
{
	if (n < 0)
		n = n * (-1);
	if (n >= 10)
	{	
		if (n == 10)
			return ('a');
		if (n == 11)
			return ('b');
		if (n == 12)
			return ('c');
		if (n == 13)
			return ('d');
		if (n == 14)
			return ('e');
		if (n == 15)
			return ('f');
	}
	else if (n < 10 && n >= 0)
		return (n + '0');
	return ('0');
}

char	*ft_dec_to_hex(unsigned int dec, char conv)
{
	int		i;
	int		mod;
	char	*str_nb;

	str_nb = malloc(1000);
	if (!str_nb)
		return (NULL);
	i = 0;
	while (dec != 0 || (dec == 0 && i == 0))
	{	
		mod = dec % 16;
		if (conv == 'x')
			str_nb[i] = ft_itoa_hexa_min(mod);
		else if (conv == 'X')
			str_nb[i] = ft_itoa_hexa_maj(mod);
		else
			str_nb[i] = ft_itoa_hexa_min(mod);
		dec = dec / 16;
		i++;
	}
	str_nb[i] = '\0';
	ft_str_reverse(str_nb);
	return (str_nb);
}
