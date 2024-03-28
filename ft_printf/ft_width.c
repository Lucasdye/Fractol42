/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:45:52 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/28 18:24:53 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_index
{
	int	i;
	int	j;
}				t_index;

void	ft_initialise_idx(t_index *p)
{
	p->i = 0;
	p->j = 0;
}

void	ft_width_precis(const char *brut, t_Los *width)
{
	char	*width_char;
	t_index	idx;

	ft_initialise_idx(&idx);
	width_char = malloc(12);
	if (!width_char)
		return ;
	while (brut[idx.i] != '.')
		idx.i++;
	idx.i--;
	while (brut[idx.i] >= '0' && brut[idx.i] <= '9')
		idx.i--;
	idx.i++;
	while ((brut[idx.i] >= '0' && brut[idx.i] <= '9') && idx.j < 11)
		width_char[idx.j++] = brut[idx.i++];
	width_char[idx.j] = '\0';
	width->bfp = ft_atoi(width_char);
	width_char = ft_memset(width_char, ' ', 12);
	idx.j = 0;
	idx.i++;
	while ((brut[idx.i] >= '0' && brut[idx.i] <= '9') && idx.j < 11)
		width_char[idx.j++] = brut[idx.i++];
	width_char[idx.j] = '\0';
	width->afp = ft_atoi(width_char);
	return (free(width_char));
}

void	ft_width(const char *brt, t_Los *width, t_Lof *flag)
{
	char	*width_char;
	t_index	idx;

	ft_initialise_idx(&idx);
	width_char = malloc(12);
	if (!width_char)
		return ;
	if (flag->precis != -1)
		ft_width_precis(brt, width);
	else
	{
		while ((brt[idx.i] <= '0' || brt[idx.i] > '9')
			&& ft_char_conv_id(brt[idx.i]) == 0)
			idx.i++;
		if (ft_char_conv_id(brt[idx.i]) == FALSE)
		{
			while (brt[idx.i] >= '0' && brt[idx.i] <= '9')
				width_char[idx.j++] = brt[idx.i++];
			width_char[idx.j] = '\0';
			width->padding = ft_atoi(width_char);
		}
		else
			return (free(width_char));
	}
	return (free(width_char));
}
