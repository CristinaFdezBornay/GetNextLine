/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:58:12 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/17 18:40:35 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	if (str != NULL && c != (char)NULL)
	{
		if (str[0] == '\0')
			return (0);
		else if (str[0] != c)
		{
			while (*str != c && *str != '\0')
				str++;
			return (1 + ft_count_words(str, c));
		}
		else if (str[0] == c)
		{
			while (*str == c && *str != '\0')
				str++;
			return (ft_count_words(str, c));
		}
		return (0);
	}
	return ((int)NULL);
}

static char	*ft_dup(const char *s, char c)
{
	int		i;
	char	*out;

	if (s != NULL && c != (char)NULL)
	{
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (!(out = (char*)malloc((sizeof(char) * (i + 1)))))
			return (NULL);
		i = 0;
		while (s[i] != c && s[i] != '\0')
		{
			out[i] = s[i];
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nw;
	char	**out;

	if (s != NULL && c != (char)NULL)
	{
		i = 0;
		nw = ft_count_words((char*)s, c);
		if (!(out = (char**)malloc(sizeof(char*) * (nw + 1))))
			return (NULL);
		while (*s == c && *s != '\0')
			s++;
		while (i < nw)
		{
			out[i] = ft_dup(s, c);
			while (*s != c && *s != '\0')
				s++;
			while (*s == c && *s != '\0')
				s++;
			i++;
		}
		out[i] = 0;
		return (out);
	}
	return (NULL);
}
