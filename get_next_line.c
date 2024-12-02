/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:08:56 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/12/02 12:09:23 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Je dois remplir ma variable temporaire de ce que je nai pas encore utilise 
char	*fill_temp(char *buffer)
{
	
}

// Lire le file descriptor jusqu au \n ou \0
char	*read_buffer(int fd, char *line, char *buffer)
{
	size_t	nb_read;
	int		i;

	i = 0;
	nb_read = 1;
	while(nb_read > 0 && (!ft_strchr(buffer, '\n')))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		printf("Mon buffer : %s\n", buffer);
		buffer[nb_read] = '\0';	
		if (nb_read == -1)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			{
				while (buffer[i] != '\n' && buffer[i])
					i++;
				if (buffer[i] == '\n')
					line = ft_substr(buffer, 0, i + 1);
				else
					return (NULL);
				printf("Line est : %s\n", line);
				if (!line)
					return (NULL);
			}
	}
	printf("Avant de return :%s\n", line);
	return (line);
}


char	*get_next_line(int fd)
{
	char			*line;
	char			*buffer;
	static char		*temp;
	
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_buffer(fd, line, buffer);
	return (line);
}


int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	get_next_line(fd);
	//printf("%s\n", get_next_line(fd));
	close (fd);
	return (0);
}