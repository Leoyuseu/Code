#include "commen.h"

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        err_exit("socket error");

    //填写服务器端口号与IP地址
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8001);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
        err_exit("connect error");

    char buf[512] = {0};
    pid_t pid = fork();
    if (pid == -1)
        err_exit("fork error");
    //父进程: socket -> terminal
    else if (pid > 0)
    {
        int readBytes;
        while ((readBytes = read(sockfd, buf, sizeof(buf))) > 0)
        {
            cout << buf;
            memset(buf, 0, sizeof(buf));
        }
        if (readBytes == 0)
            cout << "server connect closed...\nclient exiting..." << endl;
        else if (readBytes == -1)
            err_exit("read socket error");
        kill(pid, SIGUSR1);
    }
    //子进程: keyboard -> socket
    else if (pid == 0)
    {
        signal(SIGUSR1, sigHandler);
        while (fgets(buf, sizeof(buf), stdin) != NULL)
        {
            if (write(sockfd, buf, strlen(buf)) == -1)
                err_exit("write socket error");
            memset(buf, 0, sizeof(buf));
        }
    }
    close(sockfd);
    exit(EXIT_SUCCESS);
}
