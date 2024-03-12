/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** error_handling
*/

#include "../include/server.h"

void display_error(char *error)
{
    perror(error);
    exit(84);
}

int error_handling(char *args[])
{
    for (int i = 0; i < strlen(args[1]); i++)
        if (!isdigit(args[1][i]))
            exit(84);
    if (access(args[2], X_OK) != 0)
        exit(84);
    return 0;
}
