/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:13:29 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/17 18:57:15 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i1] != '\0' && i1 < len)
	{
		while (str[i1] == to_find[i2] && i1 < len)
		{
			if (to_find[i2 + 1] == '\0')
				return ((char*)&str[i1 - i2]);
			i1++;
			i2++;
		}
		i1 = i1 - i2 + 1;
		i2 = 0;
	}
	return (0);
}
