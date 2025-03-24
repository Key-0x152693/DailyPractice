#include"server.hpp"
#include<memory>

// ./tcpserver local-port
int main(int argv,char *args[]){
    if(argv!=2){
        std::cout<<args[0]<<" local-port"<<std::endl;
        exit(0);
    }

    uint16_t localport=std::stoi(args[1]);

    std::unique_ptr<TcpServer> tsvr=std::make_unique<TcpServer>(localport);

    tsvr->InitServer();

    tsvr->Loop();

    return 0;
}
