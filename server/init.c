/*
** EPITECH PROJECT, 2024
** init.c
** File description:
** init
*/

#include "../include/server.h"

void init_struct(struct sockaddr_in *address, char *port)
{
    address->sin_family = AF_INET;
    address->sin_port = htons(atoi(port));
    address->sin_addr.s_addr = INADDR_ANY;
}

void set_clients(sock_t *sock)
{
    for (int i = 0; i < sock->nb_clients; i++) {
        if (sock->clients[i] != NULL)
            FD_SET(sock->clients[i]->fd, &sock->rfd);
    }
}

void free_all(sock_t *sock)
{
    free(sock->scwd);
    close(sock->new_sock);
    close(sock->sock);
}
