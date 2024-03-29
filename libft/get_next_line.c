/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_reborn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:26:43 by tlux              #+#    #+#             */
/*   Updated: 2018/01/16 19:23:16 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		mysubjoin(char *buf, char **line, int i)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strsub(buf, 0, i);
	tmp2 = ft_strjoin(*line, tmp);
	free(tmp);
	free(*line);
	*line = ft_strdup(tmp2);
	free(tmp2);
}

static int		handle_read(char **line, int stop, const int fd, char **reste)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;

	ret = 1;
	while (!stop && (ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		if (ret == -1)
			return (-1);
		while (buf[i] != '\n' && i < ret)
			i++;
		mysubjoin(buf, &(*line), i);
		if (buf[i] == '\n' && (stop = 1) == 1)
			if (i != (ret - 1) && i != ret)
				reste[fd] = ft_strsub(buf, i + 1, ret - i - 1);
		if (buf[i] != '\n')
			reste[fd] = NULL;
	}
	if ((ret == -1 || ret == 0) && !ft_strlen(*line))
		*line = NULL;
	if (ret == -1 || (ret == 0 && !(*line)))
		return (ret);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*reste[OPEN_MAX + 1];
	int			i;
	int			stop;

	stop = 0;
	if (fd < 0 || !(line) || !(*line = ft_strnew(1)) || BUFF_SIZE <= 0
			|| fd > OPEN_MAX)
		return (-1);
	if (reste[fd])
	{
		i = 0;
		while (reste[fd][i] != '\n' && reste[fd][i] != '\0')
			i++;
		*line = ft_strsub(reste[fd], 0, i);
		if (reste[fd][i] == '\n')
		{
			stop = 1;
			reste[fd] += (i + 1);
			if (*reste[fd] == '\0')
				reste[fd] = NULL;
		}
		else
			reste[fd] = NULL;
	}
	return (handle_read(&(*line), stop, fd, reste));
}
