#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	i = 0;
	while (argv[1][i] != '\0')
	{
		k = 0;
		while (argv[1][i] != argv[1][k] && argv[1][k] != '\0')
			k++;
		if (i == k)
			write(1, &argv[1][i], 1);
		i++;
	}

	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 0;
		while (argv[2][i] != argv[1][j] && argv[1][j] != '\0')
			j++;
		if (argv[1][j] == '\0')
		{
			k = 0;
			while (argv[2][i] != argv[2][k] && argv[2][k] != '\0')
				k++;
			if (i == k)
				write(1, &argv[2][i], 1);
		}
		i++;
	}

	write(1, "\n", 1);
	return (0);
}
