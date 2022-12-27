/*
** EPITECH PROJECT, 2022
** error_handling
** File description:
** error_handling
*/

#include <my.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * @brief Print help. That's all folks!
 *
 */
void print_help(void)
{
    my_printf("Usage: ./my_ls [OPTIONS]... [FILE]...\nList information ");
    my_printf("about the FILEs (the current directory by default).\n\n");
    my_printf("Mandatory arguments to long options are mandatory for short ");
    my_printf("options too.\n");
    my_printf("\t-a\tdo not ignore entries starting with .\n");
    my_printf("\t-l\tlist one file per line\n\t-R\t");
    my_printf("list subdirectories recursively\n\t");
    my_printf("-d\tlist directories themselves, not their contents\n\t");
    my_printf("-r\treverse order while sorting\n\t-t\tsort by time,");
    my_printf(" newest first\n");
}

/**
 * @brief Print an error message if the option is not valid.
 *
 * @param c, option character.
 */
void bad_option(char c)
{
    my_printf("my_ls: invalid option -- '%c'\n", c);
    my_printf("Try './my_ls --help' for more information.\n");
    exit(84);
}

/**
 * @brief Print an error message if the file/folder doesn't exist.
 *
 * @param path, the path of the file/folder.
 */
void not_found(char *path)
{
    my_printf("./my_ls: cannot access '%s': No such file or directory\n", path);
}
