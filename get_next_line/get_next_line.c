#include "get_next_line.h"
#include <fcntl.h>

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strndup(char *s, int n)
{
	int i = 0;
	char *t;

	if(!(t = (char *)malloc(sizeof(char) * (n + 1))))
		t = NULL;
	while (s[i] != '\0' && i < n)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char *ft_strjoin(char *a, char *b)
{
	int len_a = ft_strlen(a);
	int len_b = ft_strlen(b);
	int i;
	int j;
	char *join;

	if(!(join = (char *)malloc(sizeof(char) * (len_a + len_b + 1))))
		return (NULL);
	i = -1;
	while (++i < len_a)
		join[i] = a[i];
	j = -1;
	while (++j <len_b)
		join[i++] = b[j];
	join[i] = '\0';
	free(a);
	return (join);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	char *temp;
	static char *data;
	int byte;

	if(!(buffer = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	if (data == NULL)
	{
		data = ft_strndup("", 0);
		while ((byte = read(fd, buffer, 1)) > 0)
		{
			buffer[1] = '\0';
			data = ft_strjoin(data, buffer);
		}
	}
	free(buffer);
	byte = 0;
	while (data[byte] != '\n' && data[byte] != '\0')
		byte++;
	if (data[byte] == '\n')
	{
		*line = ft_strndup(data, byte);
		data = data + byte + 1;
		return (1);
	}
	else if (data[byte] == '\0')
	{
		*line = ft_strndup(data, byte);
		return (0);
	}
	return (0);
}

int main(void)
{
	char 	*line;
	int	ret;
	int fd;

	line = NULL;
	fd = open("text.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("%d %s\n", ret, line);
	free(line);
	while (1)
	{
	}
}