#include "utility.h"
int connected_count = 0, fail_count = 0; 

int connect(const char* host, unsigned short port, int fd)
{
		struct sockaddr_in dst_addr;
		dst_addr.sin_family = PF_INET;
		dst_addr.sin_port = htons(port);
		dst_addr.sin_addr.s_addr = inet_addr(host);

		int ret = ::connect(fd, (struct sockaddr*)&dst_addr, sizeof(dst_addr));
		if (ret >= 0)
		{
				cout << "connect ok" << endl;
				return 0;
		}
		else if (errno == 115)
			return 0;
		else
		{
				cout << "connect ret:" << ret << " errno:" << errno << endl;
				fail_count++;
				close(fd);
				return -1;
		}
}

void make_client(int epfd, int* fds, int count, const char* host, unsigned short port)
{
		for (int i = 0; i < count; i++)
		{
				int fd = socket(PF_INET, SOCK_STREAM, 0);
				if (-1 == fd)
				{
						cout << "socket err:" << errno << endl;
						break;

				}
				//setnonblocking(fd);
				addfd(epfd, fd, true, true);
				connect(host, port, fd);
				fds[i] = fd;
		}
}

int main(int argc, char *argv[])
{
		int count = 10000;
		const char* host = "127.0.0.1";
		unsigned short port = 8888;

		for (int i = 0; i < argc; i++)
			cout << argv[i] << endl;

		if (argc >= 2)
				count = atoi(argv[1]);

		if (argc >= 3)
				host = argv[2];

		if (argc >= 4)
				port = atoi(argv[3]);

		int epfd = epoll_create(EPOLL_SIZE);
		if(epfd < 0) { perror("epfd error"); exit(-1);}
		printf("epoll created, epollfd = %d\n", epfd);
		static struct epoll_event events[EPOLL_SIZE];

		int* fds = new int[count];
		int t1 = time(NULL);
		make_client(epfd, fds, count, host, port);
		int t2 = time(NULL);
		
		cout << "make client t:" << t2 - t1 << endl;
		cout << "connected count:" << connected_count << " faile count:" << fail_count << endl;
		
		while(1)
		{
				int epoll_events_count = epoll_wait(epfd, events, EPOLL_SIZE, -1);
				if(epoll_events_count < 0) {
						perror("epoll failure");
						continue;//break;
				}

				//printf("epoll_events_count = %d\n", epoll_events_count);
				for(int i = 0; i < epoll_events_count; ++i)
				{
						epoll_event& evt = events[i];
						if (evt.events & EPOLLIN||evt.events & EPOLLOUT)
						{
							connected_count++;
							if (connected_count % 1000 == 0)
							cout << "connected count:" << connected_count << endl;
						}
						else
						{
							fail_count++;
							if (fail_count % 100 == 0)
							cout << "fail count:" << fail_count << endl;
						}

				}
				if (fail_count + connected_count >= count)
					break;
		}
		t1 = time(NULL);
		cout << "connect time:" << t1 - t2 << endl;
		getchar();
		for (int i = 0; i < count; i++)
			close(fds[i]);
		close(epfd);   
		return 0;
}
