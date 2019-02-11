/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:37:48 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/15 18:52:28 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	i = 0;
	dst_cpy = (unsigned char*)dst;
	src_cpy = (unsigned char*)src;
	if (src_cpy > dst_cpy)
	{
		while (i < len)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	}
	else if (src_cpy < dst_cpy)
	{
		while (i < len)
		{
			dst_cpy[len - i - 1] = src_cpy[len - i - 1];
			i++;
		}
	}
	return (dst_cpy);
}
