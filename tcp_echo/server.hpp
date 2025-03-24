#include "Log.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace log_yhr;

const int gsockfd = -1;
const uint16_t gport = 8888;
const int gbacklog = 8;

enum
{
    SOCKET_ERROR = 1,
    BIND_ERROR,
    LISTEN_ERROR
};

class TcpServer
{
public:
    TcpServer(uint16_t port = gport) : _listen_sockfd(-1), _port(port), _running(false)
    {
    }

    void InitServer()
    {
        // 1.创建套接字
        _listen_sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
        if (_listen_sockfd < 0)
        {
            LOG(FATAL, "SOCKET CREATE ERROR!\n");
            exit(SOCKET_ERROR);
        }
        LOG(INFO, "CREATE SOCKET SUCCESS,SOCKFD:%d\n", _listen_sockfd);

        // 2.进行bind套接字
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(_port);
        local.sin_addr.s_addr = INADDR_ANY;

        if (::bind(_listen_sockfd, (struct sockaddr *)&local, sizeof(local)) < 0)
        {
            LOG(FATAL, "BIND SOCKET ERROR!\n");
            exit(BIND_ERROR);
        }
        LOG(INFO, "BIND SOCKET SUCCESS!\n");

        // 3.将套接字设置为被动监听状态
        if (::listen(_listen_sockfd, gbacklog) < 0)
        {
            LOG(FATAL, "LISTEN SOCKET ERROR!\n");
            exit(LISTEN_ERROR);
        }
        LOG(INFO, "LISTEN SOCKET SUCCESS!\n");
    }

    void Loop()
    {
        _running = true;
        while (_running)
        {
            // 4.接收新连接
            struct sockaddr_in client;
            socklen_t len = sizeof(client);
            int sockfd = ::accept(_listen_sockfd, (struct sockaddr *)&client, &len);
            if (sockfd < 0)
            {
                LOG(INFO, "ACCEPT FAILER!\n");
                continue;
            }
            // version--0
            Server(sockfd, client);
        }
    }

    ~TcpServer()
    {
        if (_listen_sockfd != -1)
        {
            ::close(_listen_sockfd);
        }
    }

private:
    void Server(int sockfd, struct sockaddr_in client)
    {
        uint16_t clientport = ntohs(client.sin_port);
        std::string clientip = inet_ntoa(client.sin_addr);
        LOG(INFO, "ACCEPT A NEW LINK, CLIENT INFO:%s:%d\n", clientip.c_str(), clientport);

        while (1)
        {
            char buffer[1024];
            ssize_t n = ::read(sockfd, buffer, sizeof(buffer) - 1);
            if (n > 0)
            {
                buffer[n] = 0;
                std::cout << "[" << clientip << ":" << clientport << "]# " << buffer << std::endl;

                std::string server_echo = "echo# ";
                server_echo += buffer;
                write(sockfd, server_echo.c_str(), sizeof(server_echo));
            }
            else if (n == 0)
            {
                LOG(INFO, "CLIENT QUIT!\n");
                break;
            }
            else
            {
                LOG(ERROR, "LOCAL READ ERROR!\n");
                break;
            }
        }
        ::close(sockfd);
    }

private:
    int _listen_sockfd;
    int _port;
    bool _running;
};