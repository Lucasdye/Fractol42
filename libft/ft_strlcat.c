/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:19:28 by lbouguet          #+#    #+#             */
/*   Updated: 2023/01/02 10:38:56 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	max_len;

	if (!size && !dst && !src)
		return (0);
	if (!size)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	max_len = ft_strlen(src) + d_len;
	if (size < d_len)
		return (ft_strlen(src) + size);
	i = 0;
	while (d_len + i < size - 1 && src[i] != '\0')
	{	
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (max_len);
}
