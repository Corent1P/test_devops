/*
** EPITECH PROJECT, 2024
** quit_cmd.c
** File description:
** quit_cmd
*/

#include "../../include/server.h"

int quit_cmd(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    dprintf(fd, "221 Service closing control connection.\r\n");
    close(sock->clients[client]->fd);
    sock->clients[client] = NULL;
    return 0;
}
