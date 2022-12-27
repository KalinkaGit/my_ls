/*
** EPITECH PROJECT, 2022
** handle_options
** File description:
** handle_options
*/

#include <ls.h>
#include <my.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>

long int get_timestamp(char *path);
void bubble_sort(long int *t, int j, int i, char **files);
void reverse_array(char **files);
char *concatenate_path_file(char *path, char *file);

/**
 * @brief Handle the options given to the program
 *
 * @param opt, option to check.
 * @param options, options given to the program.
 * @return int, option.
 */
int handle_options(char opt, int options)
{
    switch (opt) {
        case 'a':
            return ((options & 1) ? 0 : 1);
        case 'l':
            return ((options & 2) ? 0 : 2);
        case 'R':
            return ((options & 4) ? 0 : 4);
        case 'd':
            return ((options & 8) ? 0 : 8);
        case 'r':
            return ((options & 16) ? 0 : 16);
        case 't':
            return ((options & 32) ? 0 : 32);
        default:
            bad_option(opt);
    }
}

/**
 * @brief Sort the files/folders by time, reversed or not.
 *
 * @param arr, array of files/folders to sort.
 * @param reversed, 1 if reversed, 0 if not.
 */
void sort_folders_files_time(char **arr, int reversed)
{
    int i = 0;
    long int *t = malloc(sizeof(int) * 100);
    for (i; arr[i] != NULL; i++) {
        t[i] = get_timestamp(arr[i]);
    }

    for (int j = 0; j < i; j++) {
        bubble_sort(t, j, i, arr);
    }

    if (reversed == 1) {
        reverse_array(arr);
    }
}

/**
 * @brief Sort the files & folders from a folder.
 *
 * @param folder, the folder to sort.
 * @param options, the options given to the program.
 * @return char**, the sorted array.
 */
char **sort_folder(char *folder, int options)
{
    DIR *dir;
    struct dirent *entry;
    char **folders_and_files = malloc(sizeof(char *) * 100);
    int i = 0;

    if ((dir = opendir(folder)) == NULL)
        exit(84);
    while ((entry = readdir(dir)) != NULL) {
        if (options & 1 ? 1 : entry->d_name[0] != '.') {
            folders_and_files[i] = malloc(sizeof(char) * 100);
            folders_and_files[i] = concatenate_path_file(folder, entry->d_name);
            i++;
        }
    }
    folders_and_files[i] = NULL;
    sort_folders_files_time(folders_and_files, options & 16 ? 1 : 0);
    return (folders_and_files);
}
