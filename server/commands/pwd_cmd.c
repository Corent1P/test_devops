/*
** EPITECH PROJECT, 2024
** pwd_cmd.c
** File description:
** pwd_cmd
*/

#include "../../include/server.h"

int pwd_error(sock_t *sock, int client)
{
    int fd = sock->clients[client]->fd;

    if (!sock->clients[client]->id || !sock->clients[client]->mdp) {
        dprintf(fd, "530 Not logged in.\r\n");
        return 530;
    }
    return 0;
}

int pwd_cmd(sock_t *sock, int client, char **input)
{
    char *buff = malloc(sizeof(char) * 256);

    if (pwd_error(sock, client) != 0) {
        free(buff);
        return 0;
    }
    memset(buff, 0, 256);
    buff = strcat(buff, sock->clients[client]->cwd);
    buff = strcat(buff, "\r\n");
    dprintf(sock->clients[client]->fd, buff);
    free(buff);
    return 0;
}
