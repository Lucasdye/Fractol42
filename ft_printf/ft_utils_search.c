/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:38:28 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/29 12:35:43 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_conv_id(char *str)
{
	char	*conv_spec;
	int		i;
	int		j;

	conv_spec = ft_strdup("diuxXcsp");
	i = 0;
	j = 0;
	while (str[i])
	{
		while (conv_spec[j] != '\0')
		{
			if (str[i] == conv_spec[j])
				return (free(conv_spec), str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (free(conv_spec), '\0');
}

void	ft_flag(const char *brut, t_Lof *lof, char conv)
{
	int		i;

	i = 0;
	while (brut[i] && ft_char_conv_id(brut[i]) == FALSE)
	{
		if (brut[i] == '0' && (brut[i + 1] >= '0' && brut[i + 1] <= '9')
			&& (brut[i - 1] < '0' || brut[i - 1] > '9'))
			lof->zero = 1;
		if (brut[i] == '-')
			lof->hyphen = 1;
		if (brut[i] == '+')
			lof->plus = 1;
		if (brut[i] == '#' && conv == 'x')
			lof->hashtag_min = 1;
		if (brut[i] == '#' && conv == 'X')
			lof->hashtag_maj = 1;
		if (brut[i] == ' ')
			lof->space = 1;
		if (brut[i] == '.')
			lof->precis = 1;
		i++;
	}
	return ;
}

int	ft_conv_pos(char *format)
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
	return (free(set_conv), -1);
}

int	ft_char_conv_id(char a)
{
	char	*set_conv;
	int		i;

	i = 0;
	set_conv = strdup("iduxXscp");
	while (set_conv[i] != '\0')
	{
		if (set_conv[i] == a)
			return (free(set_conv), TRUE);
		i++;
	}
	return (free(set_conv), FALSE);
}
