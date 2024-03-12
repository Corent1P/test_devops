/*
** EPITECH PROJECT, 2024
** server.c
** File description:
** server
*/

#include "../include/server.h"

static void parse_clients(sock_t *sock, char *buffer)
{
    memset(buffer, 0, 512);
    for (int i = 0; i < sock->nb_clients; i++) {
        if (FD_ISSET(sock->clients[i]->fd, &sock->rfd)) {
            read(sock->clients[i]->fd, buffer, 512);
            check_input(buffer, sock, i);
        }
    }
}

static int ftp_accept(sock_t *sock, struct sockaddr_in *addr, socklen_t *addln)
{
    client_t *client;

    if (FD_ISSET(sock->sock, &sock->rfd)) {
        sock->new_sock = accept(sock->sock, (struct sockaddr *)addr, addln);
        if (sock->new_sock == -1) {
            perror("Accept error: ");
            return 84;
        }
        client = malloc(sizeof(client_t));
        dprintf(sock->new_sock, "220 Service ready for new user.\r\n");
        client->fd = sock->new_sock;
        client->cwd = strdup(sock->scwd);
        client->id = NULL;
        client->mdp = NULL;
        sock->clients[sock->nb_clients] = client;
        sock->nb_clients += 1;
    }
    return 0;
}

int ftp_loop(sock_t *sock, struct sockaddr_in *addr, socklen_t *addln)
{
    char *buffer = malloc(sizeof(char) * 513);

    sock->new_sock = 0;
    sock->nb_clients = 0;
    sock->exist = 0;
    while (1) {
        FD_ZERO(&sock->rfd);
        FD_SET(sock->sock, &sock->rfd);
        set_clients(sock);
        if (select(FD_SETSIZE, &sock->rfd, NULL, NULL, NULL) == -1)
            exit(1);
        if (ftp_accept(sock, addr, addln) == 84)
            return 84;
        parse_clients(sock, buffer);
    }
    free(buffer);
    return 0;
}

static void init_sock(sock_t *sock, struct sockaddr_in *addr,
    socklen_t addln)
{
    if (bind(sock->sock, (struct sockaddr *)addr, addln) < 0)
        display_error("Bind error: ");
    if (listen(sock->sock, 3) < 0)
        display_error("Listen error: ");
}

int ftp_server(char *port, char *cwd)
{
    sock_t sock;
    socklen_t addln = sizeof(struct sockaddr_in);
    struct sockaddr_in addr;

    sock.scwd = malloc(sizeof(char) * 513);
    sock.clients = malloc(sizeof(client_t) * 1024);
    sock.sock = socket(AF_INET, SOCK_STREAM, 6);
    if (chdir(cwd) != 0)
        return 84;
    else
        sock.scwd = getcwd(sock.scwd, 512);
    init_struct(&addr, port);
    init_sock(&sock, &addr, addln);
    FD_ZERO(&sock.rfd);
    if (ftp_loop(&sock, &addr, &addln) == 84) {
        close(sock.sock);
        return 84;
    }
    free_all(&sock);
    return 0;
}
