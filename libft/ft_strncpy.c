/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:30:57 by crfernan          #+#    #+#             */
/*   Updated: 2018/12/05 18:31:59 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len - 1)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
