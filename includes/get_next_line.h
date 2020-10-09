/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:30:16 by oem               #+#    #+#             */
/*   Updated: 2020/10/08 12:37:44 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define FD 10240

typedef struct		s_node
{
	int				fd;
	char			*buff;
	struct s_node	*next;
}					t_node;

int					get_next_line(const int fd, char **line);
#endif
