/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:51:12 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/16 11:33:42 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;

	if (s != NULL)
	{
		if (!(out = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(out, s + start, len);
		out[len] = '\0';
		return (out);
	}
	return (NULL);
}
