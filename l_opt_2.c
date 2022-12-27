/*
** EPITECH PROJECT, 2022
** l_opt_2.c
** File description:
** ls_opt_2.c
*/

#include <ls.h>
#include <my.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>

/**
 * @brief Get the user name.
 *
 * @param folder_file, folder or file.
 *
 * @return char*, user name.
 */
char *get_user(char *folder_file)
{
    struct stat file_stat;
    stat(folder_file, &file_stat);
    struct passwd *user = getpwuid(file_stat.st_uid);
    return (user->pw_name);
}

/**
 * @brief Get the group name.
 *
 * @param folder_file, folder or file.
 *
 * @return char*, group name.
 */
char *get_group(char *folder_file)
{
    struct stat file_stat;
    stat(folder_file, &file_stat);
    struct group *group = getgrgid(file_stat.st_gid);
    return (group->gr_name);
}

/**
 * @brief Print file with -l option
 *
 * @param file_folder, file or folder to print.
 */
void print_l_option_file(char *file_folder, int folder)
{
    struct stat file_stat;
    if (stat(file_folder, &file_stat) == -1)
        return;
    my_printf("%s.", get_rights(file_folder));
    my_printf(" %d", get_nlink(file_folder));
    my_printf(" %s", get_user(file_folder));
    my_printf(" %s", get_group(file_folder));
    my_printf(" %d", get_size(file_folder));
    my_printf(" %s", get_time(file_folder));
    my_printf(" %s\n", folder == 0 ? get_file_name(file_folder) : file_folder);
}

/**
 * @brief Get the folder files.
 *
 * @param files, array of files.
 * @param file_folder, file/folder.
 * @param options, options.
 * @return int, total of blocks.
 */
int get_folder_files(char **files, char *file_folder, int options)
{
    DIR *dir = opendir(file_folder);
    struct dirent *file;
    int j = 0;
    int total = 0;
    while ((file = readdir(dir)) != NULL) {
        char *name = concatenate_path_file(file_folder, file->d_name);
        if (options & 1 && file->d_name[0] == '.') {
            total += get_block_size(name);
            files[j++] = name;
        }
        if (file->d_name[0] != '.') {
            total += get_block_size(name);
            files[j++] = name;
        }
    }
    return (total);
}

/**
 * @brief Print folders/files infos
 *
 * @param file_folder, file or folder to print.
 * @param options, options.
 * @param m, if there's only 1 folder to print, don't print its name.
 */
void print_l_option(char *file_folder, int options, int m)
{
    struct stat file_stat;
    stat(file_folder, &file_stat);
    if (S_ISDIR(file_stat.st_mode) && !(options & 8)) {
        char **files = malloc(sizeof(char *) * 1000);
        int total = get_folder_files(files, file_folder, options);
        if (m != 0)
            my_printf("%s:\n", file_folder);
        my_printf("total %d\n", total);
        for (int i = 0; files[i] != NULL || files[i + 1] != NULL; i++) {
            print_l_option_file(files[i], 0);
        }
    } else {
        print_l_option_file(file_folder, 1);
    }
}
