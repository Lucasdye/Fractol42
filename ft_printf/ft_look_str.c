/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:26:31 by lbouguet          #+#    #+#             */
/*   Updated: 2023/04/13 18:55:07 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_list_str(t_Lof *lof, t_Los *los, t_Lol *len, char *arg)
{
	lof->plus = -1;
	lof->zero = -1;
	lof->precis = -1;
	lof->space = -1;
	lof->hyphen = -1;
	lof->hashtag_min = -1;
	lof->hashtag_maj = -1;
	los->bfp = -1;
	los->afp = -1;
	los->padding = -1;
	los->nb = ft_strlen(arg);
	len->zero = 0;
	len->space = 0;
	len->padding = 0;
}

int	ft_look_str(const char *brut_data, char *arg, char conv)
{
	t_Los	width;
	t_Lof	lof;
	t_Lol	len;
	char	*str;
	int		count;

	str = NULL;
	ft_init_list_str(&lof, &width, &len, arg);
	ft_flag(brut_data, &lof, conv);
	ft_width(brut_data + 1, &width, &lof);
	if (arg == NULL)
		str = ft_strdup("(null)");
	else if (arg && *arg != '\0')
		str = ft_strdup(arg);
	ft_sort_str(&lof, &width, str, &len);
	ft_print_str(&lof, &width, &len, str);
	count = len.padding + len.zero + len.space + ft_strlen(str);
	if (str)
		free(str);
	return (count);
}
