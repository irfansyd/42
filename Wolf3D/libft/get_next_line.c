/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboudouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:10:25 by sboudouk          #+#    #+#             */
/*   Updated: 2014/11/22 15:35:28 by sboudouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "includes/libft.h"

static int		gnl_check_stock(char **stock, char **line)
{
	char			*tmp;

	if (stock)
	{
		if ((tmp = ft_strchr(*stock, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(*stock);
			*stock = ft_strdup(tmp + 1);
			tmp = NULL;
			return (1);
		}
	}
	return (0);
}

static int		gnl_check_read(char *buffer, char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	char			*buffer;
	int				ret;

	if (!line || fd < 0 || fd > 256)
		return (-1);
	if (gnl_check_stock(&stock, line))
		return (1);
	buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (gnl_check_read(buffer, &stock, line))
			return (1);
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	if (ret == -1 || line == NULL)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (0);
}
