/*
** EPITECH PROJECT, 2024
** cwd_cmd.c
** File description:
** cwd_cmd
*/

#include "../../include/server.h"

int cwd_error(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (!sock->clients[client]->id || !sock->clients[client]->mdp) {
        dprintf(fd, "530 Not logged in.\r\n");
        return 530;
    }
    if (!input[1]) {
        dprintf(fd, "500 Syntax error in parameters or arguments.\r\n");
        return 500;
    }
    return 0;
}

int cwd_cmd(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;
    char *buff = malloc(sizeof(char) * 512);

    if (cwd_error(sock, client, input) != 0)
        return 0;
    chdir(sock->clients[client]->cwd);
    if (chdir(input[1]) == 0) {
        sock->clients[client]->cwd = strdup(getcwd(buff, 512));
        chdir(sock->scwd);
        dprintf(fd, "250 Requested file action okay, completed.\r\n");
    } else {
        dprintf(fd, "550 Requested action not taken. File unavailable\r\n");
        return 550;
    }
    free(buff);
    return 0;
}
