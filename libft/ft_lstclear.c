/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:21 by lbouguet          #+#    #+#             */
/*   Updated: 2023/06/23 18:23:07 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_Node **lst)
{
	t_Node	*p;

	p = (*lst);
	while (p)
	{	
		p = (*lst)->next;
		if ((*lst) != NULL)
			free((*lst));
		(*lst) = p;
	}
	lst = NULL;
}
