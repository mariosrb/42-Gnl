
#include "get_next_line.h"

int	is_chr(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return 1;
		i++;
	}
	return 0;
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