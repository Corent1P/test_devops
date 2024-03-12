/*
** EPITECH PROJECT, 2024
** client_cli.c
** File description:
** client_cli
*/

#include "../include/server.h"
#include "../include/commands.h"

char *clean_input(char *buffer)
{
    int j = 0;
    char *res = malloc(sizeof(char) * strlen(buffer) + 1);

    for (int i = 0; i < strlen(buffer); i++) {
        if ((buffer[i] < 127 && buffer[i] > 32) || buffer[i] == ' ') {
            res[j] = buffer[i];
            j++;
        }
    }
    res[j] = 0;
    return res;
}

static int unknown_cmd(int exist, int fd)
{
    if (exist == 0)
        dprintf(fd, "500 Syntax error, command unrecognized.\r\n");
    return 0;
}

int check_input(char *buffer, sock_t *sock, int client)
{
    char **input = NULL;
    char *commands[] = {"USER", "PASS", "PWD", "CWD", "HELP", "QUIT",
    "NOOP", "CDUP"};
    int (*cmd_fcts[])(sock_t *sock, int client, char **input) = {&user_cmd,
    &pass_cmd, &pwd_cmd, &cwd_cmd, &help_cmd, &quit_cmd, &noop_cmd,
    &cdup_cmd};

    buffer = clean_input(buffer);
    if (strlen(buffer) < 1)
        return 0;
    input = my_str_to_word_array(buffer, ' ');
    for (int i = 0; i < 8; i++) {
        if (input[0] && strcmp(input[0], commands[i]) == 0) {
            sock->exist = 1;
            cmd_fcts[i](sock, client, input);
        }
    }
    free(input);
    unknown_cmd(sock->exist, sock->clients[client]->fd);
    return 0;
}
