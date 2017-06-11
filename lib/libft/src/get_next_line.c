/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:31:49 by crenfrow          #+#    #+#             */
/*   Updated: 2016/12/09 03:21:50 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	handle_line(char *buff, char **line)
{
	int		llen;

	llen = ft_strlchr(buff, '\n');
	*line = ft_realloc(*line, llen + ft_strlen(*line));
	*line = ft_strjoin(*line, ft_strsub(buff, 0, llen));
	return (llen);
}

static char	*adv_buff(char *buff, int llen)
{
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE);
	tmp = ft_strcpy(tmp, buff + llen + 1);
	free(buff);
	return (tmp);
}

static int	read_buff(const int fd, char **line, char **buff)
{
	int ret;

	if ((ret = read(fd, *buff, BUFF_SIZE)) <= 0)
	{
		handle_line(*buff, line);
		if (*line[0])
			return (1);
		return (ret);
	}
	return (-42);
}

int			get_next_line(const int fd, char **line)
{
	static char		*buff;
	int				llen;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!buff)
		buff = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(1);
	while (1)
	{
		if (!buff[0])
			if ((ret = read_buff(fd, line, &buff)) != -42)
				return (ret);
		llen = handle_line(buff, line);
		if (llen < BUFF_SIZE && buff[llen] == '\n')
		{
			buff = adv_buff(buff, llen);
			return (1);
		}
		ft_strclr(buff);
	}
}
