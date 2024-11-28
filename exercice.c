
#include "get_next_line.h"

/*char	*ft_strchr(const char *s, int c)
{
	unsigned char	u_c;

	u_c = (unsigned char)c;
	while (*s)
	{
		if (*s == u_c)
			return ((char *)s);
		s++;
	}
	if (u_c == '\0')
		return ((char *)s);
	return (NULL);
}*/

char	*gnl(int fd)
{
	char	*cache = NULL;
	static char	*temp;
	char	*buffer = NULL;
	int		nb_read;
	char	*new_temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	nb_read = read(fd, buffer, BUFFER_SIZE);
	while (nb_read > 0)
	{
		temp = ft_strdup(buffer);
		if (!cache)
			cache = ft_strdup(temp);
		else
		{
			cache = ft_strjoin(cache, temp);
		}
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = '\0';
	}
	return (cache);
}



int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	printf("%s\n", gnl(fd));
	close (fd);
	return (0);
}