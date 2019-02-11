/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:47:23 by crfernan          #+#    #+#             */
/*   Updated: 2018/12/10 11:52:57 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_realloc(char **tab, size_t len)
{
	char	*tmp;
	int		out;

	if (*tab != NULL)
	{
		if (!(tmp = ft_strdup(*tab)))
			return (-1);
		free(*tab);
		out = (int)ft_strlen(tmp);
		if (!(*tab = ft_strnew(len + out)))
			return (-1);
		ft_strcpy(*tab, tmp);
		free(tmp);
	}
	else
	{
		if (!(*tab = ft_strnew(len)))
			return (-1);
		out = 0;
	}
	return (out);
}
