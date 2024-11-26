/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:08:56 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/26 17:27:51 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	static char		*buffer;

	return (line);
}

int	main(void)
{
	char	buffer_bytes[BUFFER_SIZE];
	char	*buffer;
	int		fd;

	fd = open("fichier.txt", O_RDONLY);
	return (0);
}