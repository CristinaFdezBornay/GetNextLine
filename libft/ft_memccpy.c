/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:52:59 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/15 11:27:28 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	unsigned char		*dst_cpy;
	unsigned char		*src_cpy;
	size_t				i;

	i = 0;
	dst_cpy = (unsigned char*)dst;
	src_cpy = (unsigned char*)src;
	while (i < n && src_cpy[i] != (unsigned char)c)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		dst_cpy[i] = src_cpy[i];
		return (dst + i + 1);
	}
}
