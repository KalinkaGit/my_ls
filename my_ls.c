/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_ls
*/

#include <ls.h>
#include <my.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <errno.h>

void sort_folders_files_time(char **files, int reversed);
int print_single(char **folders, char **files, int options);
int print_multiple(char **folders, char **files, int options, int first);
char *concatenate_path_file(char *path, char *file);

/**
 * @brief Add to folders array all the folders in the string 'folder_to_check'
 *
 * @param folders, the array of folders
 * @param folder_to_check, the path to the folder to check
 * @param count, the number of folders in the folders array
 * @return int, the number of folders in the folders array
 */
int get_folders_recursive(char **folders, char *folder_to_check, int count)
{
    DIR *dir = opendir(folder_to_check);
    struct dirent *entry;
    char *path = NULL;

    if (dir == NULL)
        exit(84);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.' && entry->d_type == DT_DIR) {
            path = concatenate_path_file(folder_to_check, entry->d_name);
            folders[count] = path;
            count++;
        }
    }
    closedir(dir);
    return (count);
}

/**
 * @brief Execute the right print function depending on the number of folders
 * and files
 *
 * @param folders, array of folders.
 * @param files, array of files.
 * @param options, options given by the user.
 */
void my_ls(char **folders, char **files, int options)
{
    int count = 0;

    for (int i = 0; folders[i] != NULL; i++)
        count++;

    if ((options & 4) && (options & 8) == 0)
        for (int i = 0; folders[i] != NULL; i++)
            count = get_folders_recursive(folders, folders[i], count);

    for (int i = 0; files[i] != NULL; i++)
        count++;

    if (count > 1)
        options = print_multiple(folders, files, options, 1);
    else
        options = print_single(folders, files, options);

    if (!(options & 64) && !(options & 2))
        my_printf("\n");
}

/**
 * @brief Add the path to the right array.
 *
 * @param path, the path to the file/folder
 * @param folders, the array of folders
 * @param files, the array of files
 */
void handle_files(char *path, char **folders, char **files)
{
    struct stat file_stat;
    static int j = 0;
    static int k = 0;

    if (stat(path, &file_stat) == -1)
        exit(84);

    if (file_stat.st_mode & S_IROTH) {
        if (S_ISDIR(file_stat.st_mode)) {
            folders[j] = malloc(sizeof(char) * (my_strlen(path) + 1));
            folders[j] = path;
            j++;
        } else {
            files[k] = malloc(sizeof(char) * (my_strlen(path) + 1));
            files[k] = path;
            k++;
        }
    } else
        exit(84);
}

/**
 * @brief Get the folders and files object, sort them if needed.
 *
 * @param ac count of arguments
 * @param av arguments
 * @return int error code
 */
int main(int ac, char **av)
{
    int options = 0;
    char **folders = malloc(sizeof(char *) * 1000);
    char **files = malloc(sizeof(char *) * 1000);

    if (ac == 1 || (ac == 2 && av[1][0] == '-'))
        folders[0] = ".";
    for (int i = 1; i != ac; i++)
        options += handle_args(av[i], folders, files);
    if (options & 32) {
        sort_folders_files_time(folders, (options & 16 ? 1 : 0));
        sort_folders_files_time(files, (options & 16 ? 1 : 0));
    }
    my_ls(folders, files, options);
    return (0);
}
