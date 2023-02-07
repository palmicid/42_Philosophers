#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

void	putendl_test(char *str)
{
	int	i = 0;
	while (str && str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

int mails = 0;
int	lock = 0;

void	*routine()
{
	for (int i = 0; i < 100; i++)
	{
		lock = 1;
		mails++;
		lock = 0;
}


int	main(void)
{
	pthread_t t1, t2;

	if ((pthread_create(&t1, NULL, &routine, NULL)) != 0)
		return 1;
	//pthread_join(t1, NULL);
	if ((pthread_create(&t2, NULL, &routine, NULL)) != 0)
		return 2;
	if (pthread_join(t1, NULL) != 0)
		return 3;
	if (pthread_join(t2, NULL) != 0)
		return 4;
	pthread_mutex_destroy()
	printf("Number of mails = %d\n", mails);
	return (0);
}