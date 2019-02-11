/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:01:21 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/15 16:54:33 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_lenn(long n)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	i++;
	return (i);
}

static char		*ft_nbr(char *s, long n)
{
	if (n < 0)
	{
		*s = '-';
		s++;
		n *= -1;
	}
	if (n >= 10)
	{
		s = ft_nbr(s, (n / 10));
		s = ft_nbr(s, (n % 10));
	}
	else if (n < 10)
	{
		*s = n + '0';
		s++;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*out;

	i = 0;
	if (!(out = (char*)malloc(sizeof(char) * (ft_lenn((long)n) + 1))))
		return (NULL);
	ft_nbr(out, (long)n);
	*(out + ft_lenn((long)n)) = '\0';
	return (out);
}
