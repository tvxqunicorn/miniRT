/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:12:28 by xli               #+#    #+#             */
/*   Updated: 2021/05/04 09:18:50 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstlen > dstsize)
	{
		return (srclen + dstsize);
	}
	while (src[i] && i + dstlen + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

void	ft_strcat(char *s1, char *s2)
{
	int	n;
	int	i;

	n = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[n + i] = s2[i];
		i++;
	}
	s1[n + i] = '\0';
}
