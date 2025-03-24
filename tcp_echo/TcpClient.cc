#include "Log.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace log_yhr;

// ./tcpclient server-ip server-port
int main(int argv, char *args[])
{
    if (argv != 3)
    {
        std::cout << args[0] << " server-ip server-port" << std::endl;
        exit(0);
    }

    // 1.创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        LOG(FATAL, "CLIENT SOCKET CREATE ERROR!\n");
        exit(1);
    }

    //客户端不需要显示的bind，但是一定要有自己的IP和port，所以需要隐式的bind，OS会用客户端的IP和随机端口号自动bind sockfd

    // 2.向服务器发起连接请求
    
    struct sockaddr_in server;
    memset(&server,0,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(std::stoi(args[2]));
    server.sin_addr.s_addr=inet_addr(args[1]);
    socklen_t len = sizeof(server);

    int n = connect(sockfd, (struct sockaddr *)&server, len);
    if (n < 0)
    {
        LOG(FATAL, "CONNECT SOCKET CREATE ERROR!\n");
        exit(1);
    }

    while (1)
    {
        std::string line;
        std::cout << "Say # ";
        getline(std::cin, line);
        // std::cout<<line<<std::endl;
        if (line == "quit")
        {
            std::cout << "client quit" << std::endl;
            break;
        }
        ssize_t n = write(sockfd, line.c_str(), sizeof(line));
        if (n > 0)
        {
            char buffer[1024];
            int n = read(sockfd, buffer, sizeof(buffer) - 1);
            buffer[n]=0;
            std::cout<<"SERVER ECHO# "<<buffer<<std::endl;
        }
        else
        {
            LOG(ERROR, "CLIENT WRITE FAILED!\n");
        }
    }

    return 0;
}