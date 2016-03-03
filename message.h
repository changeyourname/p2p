#include<iostream>
#include<string.h>
#include<vector>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<errno.h>
#define MSG_SUCCESS 100
#define MSG_FAILED 101
#define MSG_REQUIRE_LOGIN 200
#define MSG_LOGIN 201
#define MSG_LOGOUT 202
#define MSG_REQUEST_DIG 300
class message
{
	private:
	struct standard_msg
	{
		int msg_header;
		std::string msg_text;
		};
	struct standard_msg* msg_ptr;
	public:
	int send_message(int socket_fd,int header,std::string text);
	};
