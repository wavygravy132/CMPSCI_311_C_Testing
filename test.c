#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>

void create_serv()
{
    struct sockaddr_in saddr = {AF_INET, htons(16453), htonl(INADDR_ANY)};
    int serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    int bind_success = bind(serv_fd, (struct sockaddr *)&saddr, sizeof(saddr));
    printf("bound 0/-1 %d\n", bind_success);
    listen(serv_fd, 5);

    struct sockaddr_in caddr;
    socklen_t caddr_len = sizeof(caddr);
    int client_fd = accept(serv_fd, (struct sockaddr *)&caddr, &caddr_len);

    char *addr_str = inet_ntoa(caddr.sin_addr);
    printf("client connected from %s\n", addr_str);
    close(client_fd);
    close(serv_fd);
}

void fork_test()
{
    printf("starting parent process\n");
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed\n");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        printf("child processing\n");
        sleep(1);
        exit(19);
    }
    else
    {
        printf("parent forked a child with pid = %d\n", pid);
        int status;
        wait(&status);
        printf("child exited with status = %d\n", WEXITSTATUS(status));
    }
}

int main(int argc, char *argv[])
{
    printf("hello world\n");

    //create_serv();
    fork_test();

    return 0;
}