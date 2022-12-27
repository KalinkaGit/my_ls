/*
** EPITECH PROJECT, 2022
** handle_args
** File description:
** handle_args
*/

#include <ls.h>
#include <my.h>
#include <stdlib.h>

/**
 * @brief Handle the arguments given to the program
 *
 * @param av, the arguments given to the program.
 * @param folders, the array of folders.
 * @param files, the array of files.
 * @return int, options.
 */
int handle_args(char *av, char **folders, char **files)
{
    int options = 0;
    if (av[0] == '-' && my_strcmp(av, "--help") != 0
        && my_strcmp(av, "-") != 0) {
        for (int i = 1; av[i] != '\0'; i++) {
            options += handle_options(av[i], options);
        }
    } else if (my_strcmp(av, "--help") == 0) {
        print_help();
        exit(0);
    } else {
        handle_files(av, folders, files);
    }
    return (options);
}

/**
 * @brief Check if folder is empty
 *
 * @param folder, the folder to check.
 * @return int, 1 if empty, 0 if not.
 */
int is_folder_empty(char *folder)
{
    struct stat file_stat;
    stat(folder, &file_stat);
    if (file_stat.st_size == 0)
        return (1);
    return (0);
}
