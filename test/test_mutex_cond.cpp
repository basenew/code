#include <pthread.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

pthread_mutex_t mt;
pthread_cond_t condc, condp;
int buffer;

void *producer(void* loop_times)
{
	int times = *(int*)loop_times;
	for (int i = 1; i <= times; i++)
	{
		pthread_mutex_lock(&mt);
		//while (buffer != 0)pthread_cond_wait(&condp, &mt);	
		buffer = i;
		cout << "p:" << i << endl;
		//pthread_cond_signal(&condc);
		pthread_mutex_unlock(&mt);
	}	
}

void *consumer(void* loop_times) 
{
	int times = *(int*)loop_times;
	for (int i = 1; i <= times; i++)
	{
		pthread_mutex_lock(&mt);
		//while (buffer == 0)pthread_cond_wait(&condc, &mt);	
		buffer = 0;
		cout << "c:" << i << endl;
		//pthread_cond_signal(&condp);
		pthread_mutex_unlock(&mt);
	}	

}

int main(int argc, char** argv)
{
	int times = 100;
	if (argc > 1)
		times = atoi(argv[1]);
	pthread_t pro, con;
	pthread_mutex_init(&mt, 0);
	pthread_cond_init(&condp, 0);
	pthread_cond_init(&condc, 0);

	pthread_create(&con, 0, consumer, (void*)&times);
	pthread_create(&pro, 0, producer, (void*)&times);

	pthread_join(pro, 0);
	pthread_join(con, 0);

	pthread_cond_destroy(&condp);
	pthread_cond_destroy(&condc);
	pthread_mutex_destroy(&mt);

	return 0;
}
