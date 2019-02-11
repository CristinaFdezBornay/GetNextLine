/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:19:31 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/16 10:48:52 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*out;

	if (s1 != NULL && s2 != NULL)
	{
		len = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
		if (!(out = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_strcpy(out, s1);
		ft_strcat(out, s2);
		return (out);
	}
	return (NULL);
}
