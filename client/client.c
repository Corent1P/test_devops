/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

void print_help(void)
{
    printf("Help\n");
}

void init_struct(struct sockaddr_in *client, char *port, char *ip)
{
    client->sin_family = AF_INET;
    client->sin_port = htons(atoi(port));
    client->sin_addr.s_addr = inet_addr(ip);
}

int ftp_client(char *ip, char* port)
{
    int client_fd = 0;
    int control = 0;
    char oui[32000];
    struct sockaddr_in client;
    init_struct(&client, port, ip);
    client_fd = socket(AF_INET, SOCK_STREAM, 6);
    control = connect(client_fd, (struct sockaddr*)&client, sizeof(client));
    read(client_fd, oui, strlen(oui));
    printf("Server Said: %s\n", oui);
    dprintf(client_fd, "CLIENT");
    return 0;
}

int main(int ac, char *av[])
{
    if (ac != 3) {
        print_help();
        return 84;
    }
    ftp_client(av[1], av[2]);
    return 0;
}
