/*
** EPITECH PROJECT, 2024
** help_cmd.c
** File description:
** help_cmd
*/

#include "../../include/server.h"

int help_error(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (input[1]) {
        dprintf(fd, "500 Syntax error in parameters or arguments.\r\n");
        return 500;
    }
    return 0;
}

int help_cmd(sock_t *sock, int client, char **input)
{
    if (help_error(sock, client, input) != 0)
        return 0;
    dprintf(sock->clients[client]->fd, "214 Help message.\r\n");
    return 0;
}
