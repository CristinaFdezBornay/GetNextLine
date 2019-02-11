/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 19:47:11 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/18 20:05:27 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_words_str(char *str, char c)
{
	if (str != NULL && c != (char)NULL)
	{
		if (str[0] == '\0')
			return (0);
		else if (str[0] != c)
		{
			while (*str != c && *str != '\0')
				str++;
			return (1 + ft_words_str(str, c));
		}
		else if (str[0] == c)
		{
			while (*str == c && *str != '\0')
				str++;
			return (ft_words_str(str, c));
		}
		return (0);
	}
	return ((int)NULL);
}
