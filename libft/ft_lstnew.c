/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:33:52 by lbouguet          #+#    #+#             */
/*   Updated: 2022/12/22 20:04:00 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_Node	*ft_lstnew(int content)
{
	t_Node	*element;

	element = malloc(sizeof (t_Node));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
