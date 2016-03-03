#include<iostream>
#include<string.h>
#include<vector>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<errno.h>
#include"message.h"
#include"ioreuse.h"
#define MAIN_PORT 16384
#define BACKLOG 10
using namespace std;
class p2p_server {
private:
  struct user_info {
  	int user_id;
    string user_name;
    int user_socket_fd;
    struct sockaddr_in user_addr;
    bool login_state;
  };
    vector < struct user_info >user_info_list;
public:
  int startup(int main_port);
  int add_user_info();
  int remove_user_info;
  void accept_user_connection();
  struct user_info get_user_info();
};
