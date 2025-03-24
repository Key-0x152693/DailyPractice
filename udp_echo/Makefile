.PHONY:all
all:udpserver udpclient

udpserver:ServerMain.cc
	@g++ $^ -o $@ -std=c++14
udpclient:ClientMain.cc
	@g++ $^ -o $@ -std=c++14

.PHONY:clean 
clean:
	@rm -rf udpclient udpserver
