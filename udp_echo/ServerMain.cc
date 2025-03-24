#include"server.hpp"
#include<memory>
int main(int argv,char *args[]){

    if(argv!=2){
        std::cout<<args[0]<<" "<<"local-port"<<std::endl;
        exit(1);
    }
    uint16_t localport=std::stoi(args[1]);
    std::unique_ptr<UDPServer>server=std::make_unique<UDPServer>(localport);
    server->InitServer();
    server->Start();
    return 0;


}