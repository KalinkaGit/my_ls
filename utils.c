/*
** EPITECH PROJECT, 2022
** utils
** File description:
** utils
*/

#include <ls.h>
#include <my.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * @brief Get the timestamp of last modification of a file.
 *
 * @param path, the path to the file.
 * @return long int, the timestamp.
 */
long int get_timestamp(char *path)
{
    struct stat file_stat;
    if (stat(path, &file_stat) == -1)
        exit(84);
    return (file_stat.st_mtime);
}

/**
 * @brief Sort the files in a folder by time. (Descending order)
 *
 * @param t, timestamps of the files.
 * @param j, index of the timestamp to compare.
 * @param i, index of the file to sort.
 * @param files, files to sort.
 */
void bubble_sort(long int *t, int j, int i, char **files)
{
    for (int k = 0; k < i; k++) {
        if (t[j] > t[k]) {
            long int tmp = t[j];
            t[j] = t[k];
            t[k] = tmp;
            char *tmp2 = files[j];
            files[j] = files[k];
            files[k] = tmp2;
        }
    }
}

/**
 * @brief Reverse an array of strings.
 *
 * @param files, array of strings to reverse.
 */
void reverse_array(char **files)
{
    int i = 0;
    int j = 0;

    for (i = 0; files[i] != NULL; i++);
    i--;
    for (i; i > j; i--, j++) {
        char *tmp = files[i];
        files[i] = files[j];
        files[j] = tmp;
    }
}

/**
 * @brief Concatenate a path and a file name.
 *
 * @param path, path to concatenate.
 * @param file, file to concatenate.
 * @return char*, the concatenated path.
 */
char *concatenate_path_file(char *path, char *file)
{
    char *new_path = malloc(sizeof(char)*(my_strlen(path)+my_strlen(file) + 2));
    int i = 0;
    for (i; path[i] != '\0'; i++)
        new_path[i] = path[i];
    if (path[my_strlen(path) - 1] != '/') {
        new_path[i] = '/';
        i++;
    }
    for (int j = 0; file[j] != '\0'; j++) {
        new_path[i] = file[j];
        i++;
    }
    new_path[i] = '\0';
    return (new_path);
}

/**
 * @brief Get only file name from path
 *
 * @param path, complete path with file name.
 */
char *get_file_name(char *path)
{
    char *name = malloc(sizeof(char) * 1);
    int j = 0;

    for (int i = my_strlen(path) - 1; i > 0 || path[i] != '\0'; i--, j++) {
        if (path[i] == '/')
            break;
        name = my_realloc(name, sizeof(char) * j + 1);
        name[j] = path[i];
    }

    name[j] = '\0';

    return (my_revstr(name));
}
