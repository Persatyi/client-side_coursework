#define WIN32_LEAN_AND_MEAN  // Оптимізація заголовків <windows.h>

#include "connection_utils.h"

#include <windows.h>

#include "config.h"

int connect_to_server(SOCKET client_sock, const in_addr& convertrd_ip) {
  sockaddr_in server_info;

  ZeroMemory(&server_info, sizeof(server_info));

  server_info.sin_family = AF_INET;
  server_info.sin_addr = convertrd_ip;
  server_info.sin_port = htons(kServerPortNum);

  return connect(client_sock, (sockaddr*)&server_info, sizeof(server_info));
}