/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 19:21:51 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/18 19:32:35 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void			ft_sort_wordtab(char **tab, int (*ft_cmp)(char*, char*))
{
	int	i;
	int	j;
	int	len;
	int	c;

	i = 0;
	j = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len - 1)
	{
		while (j < len - 1)
		{
			c = ft_cmp(tab[j], tab[j + 1]);
			if (c > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}
