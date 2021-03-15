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
	char *dest;

	if(!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		dest = NULL;
	while (s[i] != '\0' && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strjoin(char *a, char *b)
{
	int len_a = ft_strlen(a);
	int len_b = ft_strlen(b);
	int i;
	int j;
	char *dest;

	if(!(dest = (char *)malloc(sizeof(char) * (len_a + len_b + 1))))
		return (NULL);
	i = -1;
	while (++i < len_a)
		dest[i] = a[i];
	j = -1;
	while (++j <len_b)
		dest[i++] = b[j];
	dest[i] = '\0';
	free(a);
	return (dest);
}

int get_next_line(char **line)
{
	char *buffer;
	static char *data;
	static char *temp;
	int byte;

	if (line == NULL)
		return (-1);
	if(!(buffer = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	if (data == NULL)
	{
		data = ft_strndup("", 0);
		while ((byte = read(0, buffer, 1)) > 0)
		{
			buffer[1] = '\0';
			data = ft_strjoin(data, buffer);
		}
		temp = data;
	}
	free(buffer);
	if (byte < 0)
	{
		free(data);
		return (-1);
	}
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
		free(temp);
		return (0);
	}
	return (0);
}

int main(void)
{
	int		ret;
	char	*line;

	line = NULL;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
	}
	printf("%d %s\n", ret, line);
	free(line);
}