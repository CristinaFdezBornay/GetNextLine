/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:42:55 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/16 17:19:23 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*pre;
	t_list	*out_current;

	if (lst != NULL && f != NULL)
	{
		if (!(out = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		out = f(lst);
		pre = out;
		lst = lst->next;
		while (lst)
		{
			if (!(out_current = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			out_current = f(lst);
			pre->next = out_current;
			pre = out_current;
			lst = lst->next;
		}
		out_current->next = NULL;
		return (out);
	}
	return (NULL);
}
