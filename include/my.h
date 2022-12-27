/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/

#ifndef BLOCK
    #define BLOCK
    int my_putchar(char c);
    int my_putstr(char const *str, char *modifiers);
    int my_put_nbr(int nb, char *modifiers);
    int my_compute_power_rec(int nb, int p);
    int my_strlen(char const *str);
    char *my_realloc(char *str, int size);
    char **my_realloc2(char **str, int size);
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char const *src);
    char *my_strcpy(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);

    int my_putstr_special(char const *str, char *modifiers);
    int my_put_percent(void);
    int my_put_unbr(unsigned int nb, char *modifiers);
    int my_put_hexa(int nb, char *modifiers);
    int my_put_hexa_maj(int nb, char *modifiers);
    int my_put_octal(char c, char *modifiers);
    int my_put_binary(int nb, char *modifiers);
    int my_put_pointer(void *ptr, char *modifiers);
    int my_get_nbr_len(int nb);
    int my_put_float(double nb, char *modifiers);
    int my_put_scient(double nb, char *modifiers);
    int my_put_scient_maj(double nb, char *modifiers);
    int my_put_uoctal(unsigned int nb, char *modifiers);
    int my_put_g(double nb, char *modifiers);
    int my_put_g_maj(double nb, char *modifiers);
    int my_put_a(double nb, char *modifiers);
    int my_put_a_maj(double nb, char *modifiers);
    int is_valid_format(char *str, int index, char *modifiers);
    int my_put_length(int *);
    int my_printf(char *str, ...);
#endif
