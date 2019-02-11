/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:57:51 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/12 20:18:33 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t n)
{
	size_t	out;

	if (ft_strlen(dst) + 1 <= n)
	{
		out = ft_strlen(dst) + ft_strlen(src);
		ft_strncat(dst, src, (n - ft_strlen(dst) - 1));
	}
	else
		out = ft_strlen(src) + n;
	return (out);
}
