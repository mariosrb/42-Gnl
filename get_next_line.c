/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:08:56 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/12/03 15:09:33 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Lire le file descriptor jusqu au \n ou \0
/*char	*read_buffer(int fd, char *line, char *buffer)
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
}*/
static char	*cleanup(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

char	*share_and_extract(char *storage)
{
	// Extraire de storage jusqua \n (inclu)
	// Mettre a jour storage (garder ce qu'il y a apres \n
	int		i;
	char	*line;

	i = 0;
	printf("%s\n", storage);
	while (storage[i] != '\n' && storage[i])
		i++;
	line = ft_substr(storage, 0, i + 1);
	printf("%s", line);
	return (line);
}

char	*read_and_stock(int fd, char *storage)
{
	char	*buffer;
	int		nb_read;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb_read = 1;
	if (!storage)
		storage = ft_strdup("");
	while (!ft_strchr(storage, '\n') && (nb_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (nb_read < 0)
			return (cleanup(buffer, storage));
		buffer[nb_read] = '\0';
		temp = ft_strjoin(storage, buffer);
		if (!temp)
			return (cleanup(buffer, storage));
		free(storage);
		storage = temp;
	}
	free (buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char	*line;
	
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	//printf("--%s--\n", read_and_stock(fd, storage));
	storage = read_and_stock(fd, storage);
	line = share_and_extract(storage);
	return (line);
}


int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	//get_next_line(fd);
	//printf("%s\n", get_next_line(fd));
	get_next_line(fd);
	close (fd);
	return (0);
}