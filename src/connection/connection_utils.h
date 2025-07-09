#ifndef CONNECTION_UTILS_H_
#define CONNECTION_UTILS_H_

#include <winsock2.h>

int connect_to_server(SOCKET client_sock, const in_addr& ip_to_num);

#endif  // CONNECTION_UTILS_H_