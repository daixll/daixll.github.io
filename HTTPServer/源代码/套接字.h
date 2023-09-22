

#include <netinet/in.h>

class Socket {
public:
    Socket(int port);
    ~Socket();
    int accept();
private:
    int m_sockfd;
    sockaddr_in m_addr;
};

