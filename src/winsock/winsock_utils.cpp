#define WIN32_LEAN_AND_MEAN  // Оптимізація заголовків <windows.h>

#include <windows.h>   // Базові типи та макроси Windows API
#include <winsock2.h>  // Основні сокет-функції (WSAStartup, socket, і т.д.)
#include <ws2tcpip.h>  // Сучасні функції (InetPton, getaddrinfo, IPv6)

#include <iostream>

#include "config.h"
#include "winsock.h"

#pragma comment(lib, "ws2_32.lib")  // Автоматично додає бібліотеку Ws2_32.lib для лінкування

bool startup_winsock() {
  WORD wVersionRequested;
  WSADATA wsaData;
  int errStat;  // Socket status after startup

  /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
  wVersionRequested = MAKEWORD(2, 2);

  errStat = WSAStartup(wVersionRequested, &wsaData);  //  WinSocks initialization

  if (errStat != 0) {
    return false;
  }

  return true;
}

void cleanup_winsock() {
  std::cout << "Cleanup called\n";
  WSACleanup();
}

bool resolve_server_address(in_addr& ip_out) {
  int result = inet_pton(AF_INET, kServerIP.c_str(), &ip_out);
  if (result <= 0) {
    std::cerr << "Invalid IP address format: " << kServerIP << "\n";
    return false;
  }
  return true;
}