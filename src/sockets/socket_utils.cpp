#include "socket_utils.h"

SOCKET create_server_socket() {
  SOCKET client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (client_socket == INVALID_SOCKET) {
    return INVALID_SOCKET;
  }

  return client_socket;
}