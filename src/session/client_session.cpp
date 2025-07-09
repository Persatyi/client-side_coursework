#include "client_session.h"

#include <stdio.h>     // для fgets()
#include <ws2tcpip.h>  // для WSAGetLastError()

#include <cstring>  // для strcspn()
#include <iostream>
#include <vector>

#include "config.h"

void run_client_session(SOCKET client_sock) {
  std::vector<char> servBuff(kBuffSize), clientBuff(kBuffSize);
  int packet_size = 0;

  while (true) {
    std::cout << "You (Client): ";
    fgets(clientBuff.data(), clientBuff.size(), stdin);
    clientBuff[strcspn(clientBuff.data(), "\n")] = '\0';

    if (strcmp(clientBuff.data(), "xxx") == 0) {
      shutdown(client_sock, SD_BOTH);
      closesocket(client_sock);
      WSACleanup();
      return;
    }

    packet_size = send(client_sock, clientBuff.data(), strlen(clientBuff.data()), 0);
    if (packet_size == SOCKET_ERROR) {
      std::cerr << "Can't send message to Server. Error # " << WSAGetLastError() << "\n";
      closesocket(client_sock);
      WSACleanup();
      return;
    }

    packet_size = recv(client_sock, servBuff.data(), servBuff.size(), 0);
    if (packet_size == SOCKET_ERROR || packet_size == 0) {
      std::cerr << "Can't receive message from Server. Error # " << WSAGetLastError() << "\n";
      closesocket(client_sock);
      WSACleanup();
      return;
    }

    std::cout << "Server: " << std::string(servBuff.data(), packet_size) << "\n";
  }
}