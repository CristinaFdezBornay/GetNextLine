/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:00:31 by crfernan          #+#    #+#             */
/*   Updated: 2018/12/05 18:26:27 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*out;

	i = 0;
	if (!(out = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (i < size)
	{
		out[i] = 0;
		i++;
	}
	return ((void*)out);
}
