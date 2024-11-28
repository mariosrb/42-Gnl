
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
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
}

char	*gnl(int fd)
{
	char	*cache;
	static	char	*temp;
	char	buffer[BUFFER_SIZE];
	int		nb_read;

	nb_read = read(fd, buffer, BUFFER_SIZE);
	temp = ft_strdup((const char *)buffer);
	if (!temp)
		return (NULL);
	if (!is_chr(temp))
		cache = ft_strdup((const char *)temp);
	return (cache);
}

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	printf("%s\n", gnl(fd));
	close (fd);
	return (0);
}