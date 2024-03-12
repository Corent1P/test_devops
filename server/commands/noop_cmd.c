/*
** EPITECH PROJECT, 2024
** noop_cmd.c
** File description:
** noop_cmd
*/

#include "../../include/server.h"

int noop_error(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (!sock->clients[client]->id || !sock->clients[client]->mdp) {
        dprintf(fd, "530 Not logged in.\r\n");
        return 530;
    }
    if (input[1]) {
        dprintf(fd, "500 Syntax error in parameters or arguments.\r\n");
        return 500;
    }
    return 0;
}

int noop_cmd(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (noop_error(sock, client, input) != 0)
        return 0;
    dprintf(fd, "200 Command okay.\r\n");
    return 0;
}
