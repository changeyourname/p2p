#include "message.h"
using namespace std;
int message::send_message(int socket_fd, int header, string text) {
  int i;
  struct standard_msg msg;
  memset(&msg, 0, sizeof(msg));
  msg.msg_header = header;
  msg.msg_text = text;
  i = send(socket_fd, &msg, sizeof(msg), 0);
  if (i < 0) {
    cout << "SEND FAILED:" << i << endl;
    return i;
  }
   cout << "SEND SUCCESS:" << i << endl;
  return i;
}