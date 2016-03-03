#include "p2pserver.h"
using namespace std;
int main_server_fd = 0;
class message main_msg;
class io_reuse ioreuse;
int p2p_server::startup(int main_port) {
  struct sockaddr_in main_server_addr;
  memset(&main_server_addr, 0, sizeof(main_server_addr));
  main_server_addr.sin_family = AF_INET;
  main_server_addr.sin_port = htons(MAIN_PORT);
  main_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  main_server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (main_server_fd <= 0) {
    cout << "SOCKET ERROR:" << errno << endl;
    return -1;
  }
  if (bind
      (main_server_fd, (const struct sockaddr *)&main_server_addr,
       sizeof(main_server_addr)) < 0) {
    cout << "BIND ERROR:" << errno << endl;
    return -2;
  }
  if (listen(main_server_fd, BACKLOG) < 0) {
    cout << "LISTEN ERROR:" << errno << endl;
    return -3;
  }
  ioreuse.set_none_blocking(main_server_fd);
  cout << "THE SERVER IS LISTENING ON PORT:" << MAIN_PORT << endl;
}


void p2p_server::accept_user_connection() {
  int user_fd = 0;
  struct sockaddr_in user_addr;
  while (1) {
    user_fd = accept(main_server_fd, (struct sockaddr *)&user_addr, NULL);
    if (user_fd ) {
      main_msg.send_message(user_fd, MSG_REQUIRE_LOGIN, "0");
    }
  }
}