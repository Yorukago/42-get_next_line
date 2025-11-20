/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzorreta <jzorreta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:26 by jzorreta          #+#    #+#             */
/*   Updated: 2025/11/20 23:05:34 by jzorreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FDS][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	if (fd < 0 || fd > MAX_FDS || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer[fd][0])
		{
			line = ft_strjoin(line, buffer[fd]);
			if (!line)
				return (NULL);
			if (ft_advance(buffer))
				break ;
		}
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(line), NULL);
		buffer[fd][i] = '\0';
		if (i == 0)
			break ;
	}
	return (line);
}
// this sucks im not doing this now