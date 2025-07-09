#ifndef WINSOCK_UTILS_H_
#define WINSOCK_UTILS_H_

// Конвертація IP-адреси
bool resolve_server_address(in_addr& ip_out);

// Ініціалізація бібліотеки WinSock (WSAStartup)
bool startup_winsock();

// Завершення роботи бібліотеки WinSock (WSACleanup)
void cleanup_winsock();

#endif  // WINSOCK_UTILS_H_