/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:01:43 by crfernan          #+#    #+#             */
/*   Updated: 2018/11/17 18:08:09 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*out;

	if (!(out = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (!(out->content = (void*)malloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		out->content_size = 0;
		out->content = NULL;
	}
	else
	{
		out->content_size = content_size;
		ft_memcpy(out->content, content, content_size);
	}
	out->next = NULL;
	return (out);
}
