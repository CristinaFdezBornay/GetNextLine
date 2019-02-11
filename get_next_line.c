/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:28:00 by crfernan          #+#    #+#             */
/*   Updated: 2018/12/10 19:18:55 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_buff_to_list(t_list_gnl **list, char *buff, int fd, int i)
{
	t_list_gnl		*new;
	t_list_gnl		*curr;

	curr = *list;
	while (curr && curr->next && curr->fd != fd)
		curr = curr->next;
	if (curr && (curr->fd == fd) && (buff[i + 1] != '\0'))
		curr->str = ft_strdup(buff + i + 1);
	else if (buff[i + 1] != '\0')
	{
		if (!(new = (t_list_gnl*)malloc(sizeof(t_list_gnl))))
			return (-1);
		new->str = ft_strdup(buff + i + 1);
		new->fd = fd;
		new->next = NULL;
		if (!(*list))
			*list = new;
		else
			curr->next = new;
	}
	free(buff);
	return (1);
}

int		ft_buff_to_line(char *buff, char **line, t_list_gnl **list, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	j = ft_realloc(line, i);
	ft_strncpy((*line + j), buff, i + 1);
	if (buff[i] == '\n')
		return (ft_buff_to_list(list, buff, fd, i));
	if (buff[i] == '\0')
		return (ft_read(buff, line, list, fd));
	return (-1);
}

int		ft_read(char *buff, char **line, t_list_gnl **list, int fd)
{
	int		r;

	if (buff != NULL)
		free(buff);
	if (!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	r = read(fd, buff, BUFF_SIZE);
	if (r <= 0)
	{
		free(buff);
		if (r < 0)
			return (-1);
		if (r == 0 && *line != NULL && **line != '\0')
			return (1);
		return (0);
	}
	return (ft_buff_to_line(buff, line, list, fd));
}

int		ft_gnl(const int fd, char **line, t_list_gnl **list)
{
	char		*buff;
	t_list_gnl	*pre;
	t_list_gnl	*curr;

	buff = NULL;
	curr = *list;
	pre = *list;
	while (curr != NULL && curr->fd != fd)
	{
		pre = curr;
		curr = curr->next;
	}
	if (curr != NULL)
	{
		if (pre == curr)
			*list = (*list)->next;
		buff = ft_strdup(curr->str);
		free(curr->str);
		free(curr);
		return (ft_buff_to_line(buff, line, list, fd));
	}
	else
		return (ft_read(buff, line, list, fd));
}

int		get_next_line(const int fd, char **line)
{
	static t_list_gnl		*list;

	if (fd < 0 || !(line))
		return (-1);
	*line = NULL;
	return (ft_gnl(fd, line, &list));
}
