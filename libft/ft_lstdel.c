/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:28:15 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/16 17:31:35 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*current;
	t_list	*current_next;

	if (*alst != NULL && del != NULL)
	{
		current = *alst;
		while (current)
		{
			current_next = current->next;
			del(current->content, current->content_size);
			free(current);
			current = NULL;
			current = current_next;
		}
		*alst = NULL;
	}
}
