/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:35:54 by crfernan          #+#    #+#             */
/*   Updated: 2018/12/10 12:43:08 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 20

typedef	struct	s_list_gnl
{
	int					fd;
	char				*str;
	struct s_list_gnl	*next;
}				t_list_gnl;

int				ft_buff_to_list(t_list_gnl **list,
		char *buff, int fd, int i);
int				ft_buff_to_line(char *buff, char **line,
		t_list_gnl **list, int fd);
int				ft_read(char *buff, char **line, t_list_gnl **list,
		int fd);
int				get_next_line(const int fd, char **line);
#endif
