/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzorreta <jzorreta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:28 by jzorreta          #+#    #+#             */
/*   Updated: 2025/11/20 23:03:05 by jzorreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//helpers
size_t	ft_strlen(const char *s);
size_t	ft_strlen_nl(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_advance(char *buffer);
void	*ft_memcpy(void *s1, void const *s2, size_t size);

//get next line
char	*get_next_line(int fd);

#endif