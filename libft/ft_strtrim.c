/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:38:47 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/16 12:39:10 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_ws(char *s, int order, size_t len)
{
	size_t	i;

	i = 0;
	if (order == 1)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	}
	if (order == 2)
	{
		while (s[len - i - 1] == ' ' || s[len - i - 1] == '\t' ||
				s[len - i - 1] == '\n')
			i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	char	*out;

	if (s != NULL)
	{
		len = ft_strlen(s) - ft_ws((char *)s, 1, ft_strlen(s))
			- ft_ws((char *)s, 2, ft_strlen(s));
		if (len < 1 || ft_ws((char *)s, 1, ft_strlen(s)) == ft_strlen(s))
		{
			if (!(out = (char*)malloc(sizeof(char) * 1)))
				return (NULL);
			out[0] = '\0';
			return (out);
		}
		if (!(out = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(out, s + ft_ws((char *)s, 1, ft_strlen(s)), len);
		out[len] = '\0';
		return (out);
	}
	return (NULL);
}
