/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:51:24 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/15 16:56:38 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*out;

	if (s != NULL)
	{
		i = 0;
		len = ft_strlen(s);
		if (!(out = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			*(out + i) = f((unsigned int)i, *(s + i));
			i++;
		}
		*(out + len) = '\0';
		return (out);
	}
	return (NULL);
}
