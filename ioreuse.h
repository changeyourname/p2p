#include<unistd.h>
#include<iostream>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
class io_reuse
{
	public:
	int set_none_blocking(int socket_fd);
	};
