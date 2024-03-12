/*
** EPITECH PROJECT, 2024
** user_cmd.c
** File description:
** user_cmd
*/

#include "../../include/server.h"

int user_error(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (sock->clients[client]->id) {
        dprintf(fd, "230 User logged in, proceed.\r\n");
        return 230;
    }
    if (!input[1]) {
        dprintf(fd, "500 Syntax error in parameters or arguments.\r\n");
        return 500;
    }
    return 0;
}

int user_cmd(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (user_error(sock, client, input) != 0)
        return 0;
    sock->clients[client]->id = input[1];
    if (!sock->clients[client]->mdp)
        dprintf(fd, "331 User name okay, need password.\r\n");
    else
        dprintf(fd, "230 User logged in, proceed.\r\n");
    return 0;
}
