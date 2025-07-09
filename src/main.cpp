#include <winsock2.h>

#include <iostream>
#include <string>

#include "client_session.h"
#include "config.h"
#include "connection_utils.h"
#include "socket_utils.h"
#include "winsock_utils.h"

int main() {
  // WinSock initialization
  if (!startup_winsock()) {
    std::cerr << "WinSock initialization failed. Error # " << WSAGetLastError() << "\n";
    return 1;
  } else {
    std::cout << "WinSock initialization is OK" << "\n";
  }

  // IP in string format to numeric format for socket functions. Data is in "ip_to_num"
  in_addr ip_to_num;
  if (!resolve_server_address(ip_to_num)) {
    cleanup_winsock();
    return 1;
  }

  // Socket initialization
  SOCKET client_socket = create_server_socket();
  if (client_socket == INVALID_SOCKET) {
    std::cout << "Error initialization socket # " << WSAGetLastError() << std::endl;
    cleanup_winsock();
    return 1;
  } else {
    std::cout << "Server socket initialization is OK" << std::endl;
  }

  // Establishing a connection to Server
  if (connect_to_server(client_socket, ip_to_num) != 0) {
    std::cerr << "Connection failed. Error #" << WSAGetLastError() << "\n";
    closesocket(client_socket);
    cleanup_winsock();
    return 1;
  } else {
    std::cout << "Connection established SUCCESSFULLY. Ready to send a message to Server"
              << std::endl;
  }

  // Exchange text data between Server and Client. Disconnection if a Client send "xxx"
  run_client_session(client_socket);

  closesocket(client_socket);
  cleanup_winsock();

  return 0;
}