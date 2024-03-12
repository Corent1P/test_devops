/*
** EPITECH PROJECT, 2024
** pass_cmd
** File description:
** pass_cmd
*/

#include "../../include/server.h"

int pass_error(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (sock->clients[client]->id) {
        if (input[1] || strcmp(sock->clients[client]->id, "Anonymous") != 0) {
            dprintf(fd, "530 Not logged in.\r\n");
            return 530;
        }
    }
    if (sock->clients[client]->mdp) {
        dprintf(fd, "230 User logged in, proceed.\r\n");
        return 230;
    }
    return 0;
}

int pass_cmd(sock_t *sock, int client, char **input)
{
    int fd = sock->clients[client]->fd;

    if (pass_error(sock, client, input) != 0)
        return 0;
    if (!sock->clients[client]->id)
        dprintf(fd, "332 Need account for login.\r\n");
    else
        dprintf(fd, "230 User logged in, proceed.\r\n");
    sock->clients[client]->mdp = "";
    return 0;
}
