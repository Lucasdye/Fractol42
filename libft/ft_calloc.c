/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:52:49 by lbouguet          #+#    #+#             */
/*   Updated: 2023/01/02 10:35:41 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t eCount, size_t eSize)
{
	void	*tab;

	if (eSize && (eSize * eCount) / eSize != eCount)
		return (NULL);
	tab = malloc(eCount * eSize);
	if (!tab)
		return (NULL);
	ft_bzero(tab, eSize * eCount);
	return (tab);
}
