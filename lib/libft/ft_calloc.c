/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:12:18 by xli               #+#    #+#             */
/*   Updated: 2021/04/15 15:11:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ct, size_t size)
{
	size_t	i;
	char	*dst;

	dst = ft_malloc(ct, size);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i <= ct * size)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
