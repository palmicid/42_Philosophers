#include "philo.h"

void	*routine(t_data *phi)
{
	size_t	test;
	size_t	start;

	struct timeval	ttime;

	gettimeofday(&ttime, NULL);
	start = (ttime.tv_sec * 1000) + ttime.tv_usec / 1000;
	// test = ttime.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&ttime, NULL);
		test = (ttime.tv_sec * 1000) + ttime.tv_usec / 1000;
		printf("time %d = %ld\n", phi->id, test - start);
		usleep(300);
	}
}
