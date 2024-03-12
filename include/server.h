/*
** EPITECH PROJECT, 2024
** server.h
** File description:
** server
*/

#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

typedef struct client_s {
    int fd;
    char *id;
    char *mdp;
    char *cwd;
} client_t;

typedef struct sock_s {
    int sock;
    int new_sock;
    fd_set rfd;
    client_t **clients;
    int nb_clients;
    char *scwd;
    int exist;
} sock_t;

void init_struct(struct sockaddr_in *address, char *port);
int ftp_server(char *port, char *cwd);
int error_handling(char *args[]);
void display_error(char *error);
int check_input(char *buffer, sock_t *sock, int index_client);
char **my_str_to_word_array(char *str, char c_break);
void set_clients(sock_t *sock);
void free_all(sock_t *sock);
