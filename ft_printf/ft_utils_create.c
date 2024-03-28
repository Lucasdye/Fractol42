/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:16:17 by lbouguet          #+#    #+#             */
/*   Updated: 2023/03/28 17:54:09 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_bytes_free(char *source, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(source) + 1);
	if (!dest || !source)
		return (NULL);
	while (source[i] && i < n)
	{
		dest[i] = source[i];
		i++;
	}
	free(source);
	return (dest);
}

// char	*ft_strdup(char *source)
// {
// 	char	*dest;
// 	int		i;

// 	i = 0;
// 	dest = malloc(ft_strlen(source) + 1);
// 	if (!dest || !source)
// 		return (NULL);
// 	while (source[i])
// 	{
// 		dest[i] = source[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_memset(char *ptr, char c, size_t n)
// {	
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 		ptr[i++] = c;
// 	return (ptr);
// }

void	ft_str_reverse(char *str)
{	
	int		i;
	int		j;
	int		len;
	char	tmp;

	j = 0;
	i = 0;
	len = strlen(str);
	j = len / 2;
	len--;
	while (j != 0)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		len--;
		i++;
		j--;
	}
	return ;
}
