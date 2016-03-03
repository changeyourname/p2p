#include"ioreuse.h"
using namespace std;
int io_reuse::set_none_blocking(int socket_fd) {
  int flags = fcntl(socket_fd, F_GETFL, 0);
  if (flags < 0) {
    cout << (errno) << endl;
     cout << "THE SERVER WILL EXIT" << endl;
    return -1;
  } else if (fcntl(socket_fd, F_SETFL) < 0) {
    cout << (errno) << endl;
    cout << "THE SERVER WILL EXIT" << endl;
    return -2;
  }
  cout << "SET NON-BLOCKING SUCCESS" << endl;
  return 0;
};
