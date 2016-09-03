#include "commen.h"

int main()
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1)
        err_exit("socket error");
    int on = 1;
    if (setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,
                   &on,sizeof(on)) == -1)
        err_exit("setsockopt SO_REUSEADDR error");

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8001);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listenfd, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
        err_exit("bind error");
    if (listen(listenfd, SOMAXCONN) == -1)
        err_exit("listen error");

    struct sockaddr_in clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    int clientfd = accept(listenfd, (struct sockaddr *)&clientAddr, &addrLen);
    if (clientfd == -1)
        err_exit("accept error");
    close(listenfd);
    //打印客户IP地址与端口号
    cout << "Client information: " << inet_ntoa(clientAddr.sin_addr)
         << ", " << ntohs(clientAddr.sin_port) << endl;

    char buf[512] = {0};
    pid_t pid = fork();
    if (pid == -1)
        err_exit("fork error");
    //父进程: socket -> terminal
    else if (pid > 0)
    {
        int readBytes;
        while ((readBytes = read(clientfd, buf, sizeof(buf))) > 0)
        {
            cout << buf;
            memset(buf, 0, sizeof(buf));
        }
        if (readBytes == 0)
            cout << "client connect closed...\nserver exiting..." << endl;
        else if (readBytes == -1)
            err_exit("read socket error");
        //通知子进程退出
        kill(pid, SIGUSR1);
    }
    //子进程: keyboard -> socket
    else if (pid == 0)
    {
        signal(SIGUSR1, sigHandler);
        while (fgets(buf, sizeof(buf), stdin) != NULL)
        {
            if (write(clientfd, buf, strlen(buf)) == -1)
                err_exit("write socket error");
            memset(buf, 0, sizeof(buf));
        }
    }
    close(clientfd);
    exit(EXIT_SUCCESS);
}
