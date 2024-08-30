/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:33:13 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 13:49:24 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char **buffer)
{
	char	*line;
	char	*new_buffer;
	size_t	i;

	i = 0;
	while ((*buffer)[i] != '\n')
		i++;
	(*buffer)[i] = '\0';
	line = ft_strjoin(*buffer, "\n");
	if (!line)
	{
		free(*buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(*buffer + i + 1);
	free(*buffer);
	*buffer = new_buffer;
	if (!(*buffer))
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static int	fd_is_valid(int fd)
{
	return (fd >= 0 && fd < _SC_OPEN_MAX);
}

static int	buffer_size_is_valid(void)
{
	return (BUFFER_SIZE > 0 && BUFFER_SIZE < INT_MAX);
}

char	*get_next_line(int fd)
{
	static char	*buffer[_SC_OPEN_MAX];
	char		reader[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	if (!fd_is_valid(fd) || !buffer_size_is_valid())
		return (NULL);
	bytes_read = read(fd, reader, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		reader[bytes_read] = '\0';
		if (!ft_append(&(buffer[fd]), reader))
			return (NULL);
		if (ft_strchr(buffer[fd], '\n'))
			return (get_line(&(buffer[fd])));
		bytes_read = read(fd, reader, BUFFER_SIZE);
	}
	line = NULL;
	if (bytes_read == 0 && buffer[fd] && ft_strchr(buffer[fd], '\n'))
		return (get_line(&(buffer[fd])));
	if (bytes_read == 0 && buffer[fd] && *(buffer[fd]))
		line = ft_strdup(buffer[fd]);
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (line);
}
