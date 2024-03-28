/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:53 by lbouguet          #+#    #+#             */
/*   Updated: 2023/06/23 18:19:46 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	while (size)
	{
		if (s[size] == (char)c)
			return (((char *)s) + size);
		size--;
	}
	if (s[size] == (char)c)
		return (((char *)s) + size);
	return (0);
}
