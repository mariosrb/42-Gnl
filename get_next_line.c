/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:08:56 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/29 15:34:41 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *res)
{
	
}

char	*get_next_line(int fd)
{
	char	*res;
	static char		*buffer;

	return (res);
}


int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	printf("%s\n", gnl(fd));
	close (fd);
	return (0);
}