/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzorreta <jzorreta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:28 by jzorreta          #+#    #+#             */
/*   Updated: 2025/11/13 18:38:41 by jzorreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

//helpers
int		read_and_append(int fd, char *buffer, char **res);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *string, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, const char *src);

//get next line
char	*get_next_line(int fd);
char	*read_file(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
char	*ft_free(char *buffer, char *buf);

#endif