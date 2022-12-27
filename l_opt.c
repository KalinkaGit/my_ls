/*
** EPITECH PROJECT, 2022
** l_opt
** File description:
** l_opt
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

/**
 * @brief Get the total size object
 *
 * @param folder_files, files or folder.
 * @return int, total size.
 */
int get_block_size(char *folder_files)
{
    struct stat file_stat;
    stat(folder_files, &file_stat);
    return (file_stat.st_blocks / 2);
}

/**
 * @brief Get the rights string.
 *
 * @param folder_file, file or folder.
 * @return char*, string of rights.
 */
char *get_rights(char *folder_file)
{
    struct stat file_stat;
    stat(folder_file, &file_stat);
    char *rights = malloc(sizeof(char) * 11);
    rights[0] = (S_ISDIR(file_stat.st_mode)) ? 'd' : '-';
    rights[1] = (file_stat.st_mode & S_IRUSR) ? 'r' : '-';
    rights[2] = (file_stat.st_mode & S_IWUSR) ? 'w' : '-';
    rights[3] = (file_stat.st_mode & S_IXUSR) ? 'x' : '-';
    rights[4] = (file_stat.st_mode & S_IRGRP) ? 'r' : '-';
    rights[5] = (file_stat.st_mode & S_IWGRP) ? 'w' : '-';
    rights[6] = (file_stat.st_mode & S_IXGRP) ? 'x' : '-';
    rights[7] = (file_stat.st_mode & S_IROTH) ? 'r' : '-';
    rights[8] = (file_stat.st_mode & S_IWOTH) ? 'w' : '-';
    rights[9] = (file_stat.st_mode & S_IXOTH) ? 'x' : '-';
    rights[10] = '\0';
    return (rights);
}

/**
 * @brief Get the nlink number.
 *
 * @param folder_file, folder or file.
 * @return int, nlink.
 */
int get_nlink(char *folder_file)
{
    struct stat file_stat;
    stat(folder_file, &file_stat);
    return (file_stat.st_nlink);
}

/**
 * @brief Get size of file.
 *
 * @param folder_file, folder or file.
 * @return int, size of file.
 */
int get_size(char *folder_file)
{
    struct stat file_stat;
    stat(folder_file, &file_stat);
    return (file_stat.st_size);
}

/**
 * @brief Get the date string.
 *
 * @param folder_file, folder or file.
 * @return char*, date.
 */
char *get_time(char *folder_file)
{
    struct stat file_stat;
    stat(folder_file, &file_stat);
    char *time = ctime(&file_stat.st_mtime);
    char *new_time = malloc(sizeof(char) * 13);
    for (int i = 4; i < 16; i++)
        new_time[i - 4] = time[i];
    new_time[12] = '\0';
    return (new_time);
}
