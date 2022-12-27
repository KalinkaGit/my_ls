/*
** EPITECH PROJECT, 2022
** my_realloc
** File description:
** my_realloc
*/

#include <stdlib.h>

char *my_realloc(char *str, int size)
{
    char *newstr = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i != size; i++) {
        newstr[i] = str[i];
    }

    free(str);
    str = newstr;

    return (str);
}

void **my_realloc2(void **str, int size)
{
    void **newstr = malloc(sizeof(void *) * (size + 1));

    for (int i = 0; i != size; i++) {
        newstr[i] = str[i];
    }

    free(str);
    str = newstr;

    return (str);
}
