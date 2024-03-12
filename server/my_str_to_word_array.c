/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include "../include/server.h"

int nb_line(char *str, char c_break)
{
    int count = 0;

    for (str; str[0] == c_break; str++);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c_break && str[i + 1] != c_break)
            count += 1;
    }
    count += 1;
    return count;
}

int size_line(char *str, char c_break)
{
    int a = 0;

    for (a; str[a] != c_break && str[a] != '\0'; a++);
    return a;
}

char **my_str_to_word_array(char *str, char c_break)
{
    int line_nb = nb_line(str, c_break);
    int i = 0;
    char *str_line = NULL;
    char **arr = malloc(sizeof(char *) * (line_nb + 1));

    arr[line_nb] = NULL;
    for (i; i < line_nb; i++) {
        for (; str[0] == c_break || str[0] == '\t'; ++str);
        arr[i] = strndup(str, size_line(str, c_break));
        str += size_line(str, c_break);
    }
    if (strlen(arr[i - 1]) == 0)
        arr[i - 1] = NULL;
    return (arr);
}
