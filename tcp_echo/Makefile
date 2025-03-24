.PHONY:all
all:tcpserver tcpclient
tcpserver:TcpServer.cc
	@g++ $^ -o $@ -std=c++14;
tcpclient:TcpClient.cc
	@g++ $^ -o $@ -std=c++14;

.PHONY:clean
clean:
	@rm -rf tcpserver tcpclient
