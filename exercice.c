
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
// char	*check_buffer(char *buffer)
// {
// 	int	i;
// 	char	*res;


// 	i = 0; // bonjour je suis/n mario et un chat 
// 	while (buffer[i])
// 	{
// 		if (buffer[i] == '\n')
// 			{

// 			}
// 		i++;
// 	}
// }

// char	*gnl(int fd)
// {
// 	char	*cache = NULL;
// 	static char	*temp;
// 	char	*buffer = NULL;
// 	int		nb_read;
// 	char	*new_temp;

// 	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	
// 	nb_read = read(fd, buffer, BUFFER_SIZE);
// 	while (nb_read > 0)
// 	{
// 		temp = ft_strdup(buffer);
// 		if (!cache)
// 			cache = ft_strdup(temp);
// 		else
// 		{
// 			cache = ft_strjoin(cache, temp);
// 		}
// 		nb_read = read(fd, buffer, BUFFER_SIZE);
// 		buffer[nb_read] = '\0';
// 	}
// 	return (cache);
// }

char	*extract_line(char *input)
{
	static char	*temp;
	char		*res;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (input[i] != '\n' && input[i])
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = input[j];
		j++;
	}
	if (input[i] == '\n')
	 	res[i++] = '\n';
	res[j] = '\0';
	if (input[i])
	{
	 	free(temp);
		temp = ft_strdup(&input[i]);
	}
	else
		{
			free(temp);
			temp = NULL;
		}
	//printf("%s\n", temp);
	return (res);
}

char	*extract(char *input)
{
	static char	*temp;
	char		*res;
	int			i;

	i = 0;
	while (input[i] != '\n' && input[i])
		i++;
	if (input[i] == '\n')
		res = ft_substr(input, 0, i + 1);
	else
		res = ft_substr(input, 0, i);
	if (!res)
		return (NULL);
	if (input[i] == '\n' && input[i + 1])
		temp = ft_strdup(&input[i + 1]);
	else
		{
			free(temp);
			temp = NULL;
		}
	//printf("%s\n", temp);
	return (res);
}

int	main(int ac, char **av)
{
	printf("%s\n", extract("Bonjour\nje suis un chat"));
	// int fd = open(av[1], O_RDONLY);
	// printf("%s\n", gnl(fd));
	// close (fd);
	return (0);
}