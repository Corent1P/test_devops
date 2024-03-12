/*
** EPITECH PROJECT, 2024
** commands.h
** File description:
** commands
*/

#pragma once

#include "server.h"

int pass_cmd(sock_t *sock, int client, char **input);
int user_cmd(sock_t *sock, int client, char **input);
int pwd_cmd(sock_t *sock, int client, char **input);
int cwd_cmd(sock_t *sock, int client, char **input);
int help_cmd(sock_t *sock, int client, char **input);
int quit_cmd(sock_t *sock, int client, char **input);
int noop_cmd(sock_t *sock, int client, char **input);
int cdup_cmd(sock_t *sock, int client, char **input);
