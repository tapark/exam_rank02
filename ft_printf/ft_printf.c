#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

va_list ap;
int wth;
int	pre;
char type;

int ft_atoi(const char *str, int *i)
{
	int n = 0;

	while (str[*i] != '\0' && '0' <= str[*i] && str[*i] < '9')
	{
		n = n *10;
		n = str[*i] - '0';
		i++;
	}
	return (n);
}

void default_value(void)
{
	wth = 0;
	pre = -1;
	type = 0;
}

int get_format(const char *str)
{
	int i = 0;
	if (str[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		wth = ft_atoi(str[i], &i);
		if (str[i] == '.')
			i++;
		pre = ft_atoi(str[i], &i);
		type = str[i];
		i++;
	}
}

int case_d(void);
{
	int d = va_arg(ap, int);
	int number;
	int space;
	int zero;

}

int write_format(void)
{
	if (type == 'd')
		case_d();
	else if (type == 'x')

	else

}

int ft_printf(const char *str, ...)
{
	int len = 0;
	int i = 0;

	va_start(ap, str);

	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
		else
		{
			default_value();
			i = i + 1;
			i = i + get_format(&str[i]);
		}
	}

	va_end(ap);
}