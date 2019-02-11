/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:19:21 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/16 11:48:31 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	i_null;

	i = ft_strlen(s);
	i_null = i + 1;
	while (i != 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] == (unsigned char)c)
		return ((char*)&s[i]);
	if (c == 0)
		return ((char*)&s[i_null]);
	else
		return (0);
}
