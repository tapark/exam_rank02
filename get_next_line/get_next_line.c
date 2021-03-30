#include "get_next_line.h"

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
		return (NULL);
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
	char *dest;
	int len_a = ft_strlen(a);
	int len_b = ft_strlen(b);
	int i = -1;
	int j = -1;

	if(!(dest = (char *)malloc(sizeof(char) * (len_a + len_b + 1))))
		return (NULL);
	while (++i < len_a)
		dest[i] = a[i];
	while (++j <len_b)
		dest[i++] = b[j];
	dest[i] = '\0';
	free(a);
	return (dest);
}

int get_next_line(char **line)
{
	char buffer[2];
	static char *data;
	int byte;
	int n;

	if (line == NULL)
		return (-1);
	n = 0;
	while ((byte = read(0, buffer, 1)) > 0)
	{
		buffer[byte] = '\0';
		if (data == NULL)
			data = ft_strndup(buffer, 1);
		else
			data = ft_strjoin(data, buffer);
		if (buffer[0] == '\n')
		{
			*line = ft_strndup(data, n);
			free(data);
			data = NULL;
			return (1);
		}
		n = n + byte;
	}
	if (byte < 0)
		return (-1);
	if (data != NULL)
	{
		*line = data;
		data = NULL;
		reuturn (0);
	}
	*line = ft_strndup("", 0);
	return (0);
}

int main(void)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
	}
	printf("%d %s\n", ret, line);
	free(line);
//	while (1);
}