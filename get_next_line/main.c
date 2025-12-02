/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzorreta <jzorreta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:32:13 by jzorreta          #+#    #+#             */
/*   Updated: 2025/12/02 09:43:34 by jzorreta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("get_next_line.c", O_RDONLY);
	int lines = 100;
	char *s;

	while (lines--)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
	free(s);
	close(fd);
	return(0);
}