
#include "get_next_line.h"

int	main(int ac, char **av)
{
//  Exo 1 : lire et afficher un fichierr 
	char	buffer_bytes[BUFFER_SIZE];
	char	*buffer;
	int		fd;
	int		i = 0;
	size_t	nb_read;

	// Ouvrir un fichier et verifier sil y a une erreur
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write (2, "Open failed", 11);
		return (1);
	}
	// Lecture et ecriture 
	while ((nb_read = read(fd, buffer_bytes, BUFFER_SIZE)) > 0)
		write (1, buffer_bytes, nb_read);\
	
	// Gestion des erreurs

	if (nb_read == -1)
		write (2, "Read failed", 11);

	close (fd);
	return (0);
}