/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzorreta <jzorreta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:20 by jzorreta          #+#    #+#             */
/*   Updated: 2025/11/20 23:03:24 by jzorreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

size_t	ft_strlen_nl(const char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, void const *src, size_t size)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (!dest && !source)
		return (NULL);
	while (size--)
		*dest++ = *source++;
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*joined;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen_nl(s2);
	joined = malloc(len_s1 + len_s2 + 1);
	if (!joined)
		return (NULL);
	if (s1)
	{
		ft_memcpy(joined, s1, len_s1);
		free(s1);
	}
	ft_memcpy(joined + len_s1, s2, len_s2);
	joined[len_s1 + len_s2] = '\0';
	return (joined);
}

int	ft_advance(char *buffer)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		found = 1;
		i++;
		while (buffer[i])
			buffer[j++] = buffer[i++];
	}
	buffer[j] = '\0';
	return (found);
}
