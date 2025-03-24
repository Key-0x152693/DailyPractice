#include "Log.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace log_ns;

static const int gsockfd = -1;
static const uint16_t gport = 8888;
// std::string gip = "127.0.0.1";

enum
{
    SOCKET_ERROR = 1,
    BIND_ERROR
};

class UDPServer
{
public:
    UDPServer(uint16_t port = gport) : _sockfd(gsockfd), _port(port), _running(false) {}

    void InitServer()
    {
        // socket创建
        _sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
        if (_sockfd < 0)
        {
            LOG(FATAL, "SOCKET CREATE FAILED!\n");
            exit(SOCKET_ERROR);
        }

        LOG(DEBUG, "SOCKET CREATE SUCCESS! _SOCKFD:%d\n", _sockfd);

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(_port);
        // addr.sin_addr.s_addr = inet_addr(_localip.c_str());
        addr.sin_addr.s_addr = INADDR_ANY;
        socklen_t len = sizeof(addr);

        int n = ::bind(_sockfd, (struct sockaddr *)&addr, len);
        if (n < 0)
        {
            LOG(FATAL, "SOCKET BIND FAILED!\n");
            exit(BIND_ERROR);
        }

        LOG(DEBUG, "SOCKET BIND SUCCESS!\n");
    }

    void Start()
    {
        char buf[1024];
        _running=true;
        while(_running){
            struct sockaddr_in client;
            socklen_t len=sizeof(client);
            int n=recvfrom(_sockfd,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
            if(n>0){
                int clientport=ntohs(client.sin_port);
                std::string clientip=inet_ntoa(client.sin_addr);
                buf[n]=0;
                std::cout<<"["<<clientip<<":"<<clientport<<"]# "<<buf<<std::endl;

                std::string line="[server]# ";
                line=line+buf;
                sendto(_sockfd,line.c_str(),sizeof(line),0,(struct sockaddr*)& client,len);
            }
            else{
                std::cout<<"server recvfrom error"<<std::endl;
            }
        }
    }

    ~UDPServer()
    {
        if (_sockfd != gsockfd)
            ::close(_sockfd);
    }

private:
    int _sockfd;
    uint16_t _port;
    // std::string _localip;
    bool _running;
};