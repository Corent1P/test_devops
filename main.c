/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/
#include "./include/server.h"

void print_help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user");
    putchar('\n');
    exit(0);
}

int main(int ac, char *av[])
{
    if (ac != 3)
        return 84;
    if (strcmp(av[1], "-help") == 0 && ac == 2)
        print_help();
    error_handling(av);
    ftp_server(av[1], av[2]);
    return 0;
}
