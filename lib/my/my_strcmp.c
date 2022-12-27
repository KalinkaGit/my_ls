/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int final = 0;
    int stop1 = 0;
    int stop2 = 0;

    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (stop1 == 0 && stop2 == 0)
            final = final + (s1[i] - s2[i]);
        if (s1[i] == '\0')
            stop1 = 1;
        if (s2[i] == '\0')
            stop2 = 1;
    }

    return (final);
}
