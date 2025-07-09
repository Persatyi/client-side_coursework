#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>

// Key constants
const std::string kServerIP = "127.0.0.1";  // Enter IPv4 address of Server
constexpr int kServerPortNum = 8080;        // Enter Listening port on Server side

// Maximum size of buffer for exchange info between server and client
constexpr int kBuffSize = 1024;

#endif  // CONFIG_H_