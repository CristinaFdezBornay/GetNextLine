/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:03:53 by crfernan          #+#    #+#             */
/*   Updated: 2018/12/07 17:13:09 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*out;

	i = 0;
	size++;
	if (!(out = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i != size)
	{
		out[i] = '\0';
		i++;
	}
	return (out);
}
