//
// Created by LemonPig on 2023/12/16.
//

#ifndef LEMON_CHAT_P2PNODE_H
#define LEMON_CHAT_P2PNODE_H

#define MAX_PLAYER 5

// Include Necessary Headers
// For Win32 and macOS
#ifdef _WIN32
#include <iostream>
#include <cstring>
#include <vector>
#include <winsock2.h>
#include <iphlpapi.h>
#include <Ws2tcpip.h>
#include <thread>
#include <vector>
#include <tuple>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#elif __APPLE__ || __linux__
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <vector>
#include <tuple>

#endif

// P2PNode Class

class P2PNode {
 private:

#ifdef _WIN32
  SOCKET sockfd;
#elif __APPLE__ || __linux__
  int sockfd;
#endif
  bool is_initialized;
  struct sockaddr_in addr;

 public:

  P2PNode();

  void initialize(int port);

  bool isInited() const;

  ~P2PNode();

  void send(const std::string& message, const std::string& ip, uint16_t port) const;

  std::tuple<std::string, std::string, uint16_t> receive();

  void closeConnection();

  bool is_server;

};

std::vector<std::string> getLocalIPs();

#endif //LEMON_CHAT_P2PNODE_H