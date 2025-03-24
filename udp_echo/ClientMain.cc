#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Log.hpp"
using namespace log_ns;

int main(int argv, char *args[])
{
    if (argv != 3)
    {
        std::cout << args[0] << " " << "server-ip" << " " << "server-port" << std::endl;
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    uint16_t sport = std::stoi(args[2]);
    server.sin_port = htons(sport);
    server.sin_addr.s_addr = inet_addr(args[1]);
    socklen_t len = sizeof(server);

    int sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        LOG(FATAL, "CLIENT SOCKET CREATE FAILED!\n");
        exit(1);
    }

    while (1)
    {
        std::string line;
        std::cout << "you say# ";
        getline(std::cin, line);
        std::cout<<line<<std::endl;
        if(line=="quit"){
            break;
        }
        int n = sendto(sockfd, line.c_str(), line.size(), 0, (struct sockaddr *)&server, len);
        if(n>0){
            char buf[1024];
            int n=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&server,&len);
            std::cout<<buf<<std::endl;
            if(n<0){
                std::cout<<"client recvfrom failed"<<std::endl;
            }
        }
        else{
            std::cout<<"client sendto failed"<<std::endl;
        }
    }

    return 0;
}