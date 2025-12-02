/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzorreta <jzorreta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:32:13 by jzorreta          #+#    #+#             */
/*   Updated: 2025/12/02 09:42:23 by jzorreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
	int fd1 = open("get_next_line.c", O_RDONLY);
	int fd2 = open("get_next_line_bonus.c", O_RDONLY);
	int lines = 100;
	char *s;

	while (lines--)
	{
		s = get_next_line(fd1);
		printf("%s", s);
		free(s);
		s = get_next_line(fd2);
		printf("%s", s);
		free(s);
	}
	free(s);
	close(fd1);
	close(fd2);
	return(0);
}