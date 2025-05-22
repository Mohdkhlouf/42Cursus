#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*gnl(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	index = 0;
	static int	bytes_read = 0;
	int			i;
	char		*line;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (1)
	{
		if (index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			index = 0;
			if (bytes_read <= 0)
			{
				free(line);
				return (NULL);
			}
		}
		line[i++] = buffer[index++];
		if (buffer[index - 1] == '\n' || index >= bytes_read)
			break;
	}
	line[i] = '\0';
	return (line);
}

int	main(void)
{
	int fd;
	char *line;

	// Open the file for reading
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1); // Exit with an error code if the file can't be opened
	}

	// Read and print each line from the file
	while ((line = gnl(fd)) != NULL)
	{
		printf("%s", line); // Print the line
		free(line);         // Free the memory for the line after printing
	}

	// Close the file after finishing
	close(fd);

	return (0); // Success
}