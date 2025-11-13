/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzorreta <jzorreta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:26 by jzorreta          #+#    #+#             */
/*   Updated: 2025/11/13 18:48:21 by jzorreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*temp;

	if (!buffer)
	{
		buffer = malloc(1 * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	temp = ft_strjoin(buffer, buff);
	free(buffer);
	return (temp);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;

	if (!res)
	{
		res = malloc(1 * sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_and_append(fd, buffer, &res))
		if (ft_strchr(buffer, '\n'))
			break ;
	free(buffer);
	if (!res[0])
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*ft_next(char *buffer)
{
	int		i;
	char	*next;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	i++;
	next = malloc((ft_strlen(buffer + i) + 1) * sizeof(char));
	if (!next)
		return (NULL);
	ft_strcpy(next, buffer + i);
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
