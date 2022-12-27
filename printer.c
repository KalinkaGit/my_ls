/*
** EPITECH PROJECT, 2022
** printer
** File description:
** printer
*/

#include <ls.h>
#include <my.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>

/**
 * @brief Print the file or folder name with the right format.
 *
 * @param first, 1 if it's the first file or folder to print, 0 otherwise.
 * @param name, the name of the file or folder to print.
 * @return int, 0 bcz it isn't the first file or folder to print anymore.
 */
int format_print(int first, char *name)
{
    if (first == 1) {
        my_printf("%s", name);
    } else
        my_printf("  %s", name);
    return (0);
}

/**
 * @brief Print files from a folder.
 *
 * @param folder, the folder to print.
 * @param options, options.
 */
int print_files(char *folder, int options)
{
    DIR *dir = opendir(folder);
    struct dirent *file;
    struct stat file_stat;
    int first = 1;
    if (is_folder_empty(folder) == 1)
        return (64);
    my_printf("%s:\n", folder);
    if (options & 32) {
        char **files = sort_folder(folder, options);
        for (int i = 0; files[i] != NULL; i++)
            first = format_print(first, get_file_name(files[i]));
        return (options & 64 ? -64 : 0);
    }
    while ((file = readdir(dir)) != NULL) {
        if (options & 1 && file->d_name[0] == '.')
            first = format_print(first, file->d_name);
        if (file->d_name[0] != '.')
            first = format_print(first, file->d_name);
    }
    return (options & 64 ? -64 : 0);
}

/**
 * @brief -d option, print folders without their content, see --help
 *
 * @param folders, the array of folders.
 * @param files, the array of files.
 * @param options, options.
 */
void print_d_option(char **folders, char **files, int options)
{
    int j = 0;
    int first = 1;
    char **folder_files = malloc(sizeof(char *) * 1000);
    for (int i = 0; folders[i] != NULL; i++, j++) {
        folder_files[j] = malloc(sizeof(char) * (my_strlen(folders[i]) + 1));
        folder_files[j] = folders[i];
    }
    for (int i = 0; files[i] != NULL; i++, j++) {
        folder_files[j] = malloc(sizeof(char) * (my_strlen(files[i]) + 1));
        folder_files[j] = files[i];
    }
    folders[j] = NULL;
    if (options & 32)
        sort_folders_files_time(folder_files, options & 16 ? 1 : 0);
    for (int i = 0; folder_files[i] != NULL; i++) {
        first = format_print(first, folder_files[i]);
    }
}

/**
 * @brief Print the folders and files (format is diffent this is why there is
 * 2 functions).
 *
 * @param folders, the array of folders.
 * @param files, the array of files.
 * @param options, options.
 */
int print_multiple(char **folders, char **files, int options, int first)
{
    if (options & 8 && !(options & 2)) {
        print_d_option(folders, files, options);
        return (options);
    }
    for (int i = 0; files[i] != NULL; i++)
        if (options & 2)
            print_l_option(files[i], options, 0);
        else
            first = format_print(first, files[i]);
    if (folders[0] != NULL && files[0] != NULL)
        my_printf(options & 2 ? "\n" : "\n\n");
    for (int i = 0; folders[i] != NULL; i++) {
        if (options & 2)
            print_l_option(folders[i], options, 1);
        else
            options += print_files(folders[i], options);
        if (folders[i + 1] != NULL && !(options & 64))
            my_printf(options & 2 ? "\n" : "\n\n");
    }
    return (options);
}

/**
 * @brief Print the folders and files (format is diffent this is why there is
 * 2 functions).
 *
 * @param folders, the array of folders.
 * @param files, the array of files.
 * @param options, options.
 */
int print_single(char **folders, char **files, int options)
{
    if (options & 8 && !(options & 2)) {
        print_d_option(folders, files, options);
        return (options);
    }
    if (folders[0] != NULL) {
        if (options & 2)
            print_l_option(folders[0], options, 0);
        else
            options += print_files(folders[0], options);
    } else {
        if (options & 2)
            print_l_option(files[0], options, 0);
        else
            my_printf("%s", files[0]);
    }

    return (options);
}
