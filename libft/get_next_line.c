#include "libft.h"

int get_next_line(int fd, char **line)
{
	char *buffer;
	int i = 0;
	int r = 0;
	char c;

	if (!(buffer = (char *)malloc(10000)))
		return (-1);
	while ((r = read(fd, &c, 1)) && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}