#include <string>
#include <ios>
#include <sys/socket.h>
#include <sys/un.h>
#include <chrono>
#include <thread>
#include <boost/filesystem.hpp>

namespace sockettest 
{
// manually remove the socket file first before test
static std::string TestSocketPath = "./tmp/syslog_socket";
static size_t COUNT = 10;
void client() {
        std::string socketPath = TestSocketPath;
        int sock = 0;
        struct sockaddr_un remote;

        if((sock = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) {
            std::cout << "failed to create socket" << std::endl;
        }

        memset(&remote, 0, sizeof(struct sockaddr_un));
        remote.sun_family = AF_UNIX;
        if(sizeof(remote.sun_path) < socketPath.size()) {
            exit(EXIT_FAILURE);
        }
        strncpy(remote.sun_path, socketPath.c_str(), socketPath.size());

        int i = 0;
        
        boost::filesystem::path tmpFilePath(socketPath);
        while(!boost::filesystem::exists(tmpFilePath)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        
        std::cout << "start to send message" << std::endl;
        while(++i <= COUNT) {
            std::string msg = "hello " + std::to_string(i);
            size_t cnt = 0;
            do {
                cnt = sendto(sock, msg.c_str(), msg.size(), 0, (struct sockaddr *) &remote, sizeof(struct sockaddr_un));
            } while(cnt < msg.size());
        }
        return;
}

void server() {
        std::string socketPath = TestSocketPath;
        int sock = 0;
        int dataLen = 0;
        struct sockaddr_un remote;
        char recvMsg[1024];

        if((sock = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) {
            std::cout << "failed to create socket" << std::endl;
        }

        memset(&remote, 0, sizeof(struct sockaddr_un));
        remote.sun_family = AF_UNIX;
        if(sizeof(remote.sun_path) < socketPath.size()) {
            exit(EXIT_FAILURE);
        }
        strncpy(remote.sun_path, socketPath.c_str(), socketPath.size());

        if(bind(sock, (struct sockaddr*) &remote, sizeof(struct sockaddr_un)) == -1) {
            std::cout << "failed to bind socket:" << std::endl;
            return;
        } else {
            std::cout << "socket ready" << std::endl;
        }

        int i = 0;
        while(++i <= COUNT) {
            memset(recvMsg, 0, 1024 * sizeof(char));
            if((dataLen = recv(sock, recvMsg, 1024, 0)) > 0) {
                std::cout << recvMsg << std::endl;
            } else if (dataLen < 0) {
                std::cout << "failed to recevie data from socket" << std::endl;
            } else {
                std::cout << "socket closed" << std::endl;
                close(sock);
                break;
            }
        }

        close(sock);
        boost::filesystem::remove(boost::filesystem::path(socketPath));
        return;
}
void test() {
    std::thread t1([]{server();});
    std::thread t2([]{client();});
    t1.join();
    t2.join();
}
}