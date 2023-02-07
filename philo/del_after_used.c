#include <unistd.h>

void	putendl_test(char *str)
{
	int	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
