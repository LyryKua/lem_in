/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <khrechen@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:46:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/08 10:46:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static ssize_t		ft_line(char **static_content, char **line)
{
	char			*temp;

	if (!*static_content || !**static_content || *static_content == '\0')
		return (0);
	if (!ft_strchr(*static_content, '\n'))
	{
		if (!(*line = ft_strdup(*static_content)))
			return (-1);
		ft_strdel(static_content);
	}
	else
	{
		if (!(*line = ft_strsub(*static_content, 0,
					ft_strchr(*static_content, '\n') - *static_content)))
			return (-1);
		temp = *static_content;
		*static_content = ft_strdup((ft_strchr(temp, '\n')) + 1);
		ft_strdel(&temp);
	}
	return (1);
}

static t_list		*get_temp_fd(size_t fd, t_list **static_list)
{
	t_list			*temp;

	if (*static_list)
	{
		temp = *static_list;
		while (temp)
		{
			if (temp->content_size == fd)
				return (temp);
			temp = temp->next;
		}
	}
	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	temp->content_size = fd;
	if (!(temp->content = ft_strdup("\0")))
	{
		free(temp);
		return (NULL);
	}
	temp->next = *static_list;
	*static_list = temp;
	return (temp);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*str;
	ssize_t			ret;
	static t_list	*static_list = NULL;
	t_list			*temp;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (!(temp = get_temp_fd((size_t)fd, &static_list)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = temp->content;
		temp->content = ft_strjoin(str, buff);
		ft_strdel(&str);
		if (ft_strchr((char*)temp->content, '\n'))
			break ;
	}
	if ((ret = ft_line((char**)&(temp->content), line)) == -1)
		return (-1);
	if (static_list->content == NULL || static_list->content == '\0')
		ft_strdel((char**)&static_list->content);
	return (((ret > 0) ? 1 : 0));
}
