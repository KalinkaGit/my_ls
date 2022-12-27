/*
** EPITECH PROJECT, 2022
** jsp
** File description:
** dffsfd
*/

#include <stdint.h>
#include <sys/stat.h>

#ifndef BLOCKA
    #define BLOCKA
    void print_help(void);
    void bad_option(char c);
    int handle_options(char opt, int options);
    int handle_args(char *av, char **folders, char **files);
    void handle_files(char *path, char **folders, char **files);
    int get_total_size(char **folder_files);
    char *get_rights(char *folder_file);
    int get_nlink(char *folder_file);
    int get_size(char *folder_file);
    char *get_time(char *folder_file);
    char *get_user(char *folder_file);
    char *get_group(char *folder_file);
    int get_block_size(char *file_folder);
    char *get_file_name(char *folder_file);
    char *concatenate_path_file(char *path, char *file);
    void sort_folders_files_time(char **folder_files, int reverse);
    char **sort_folder(char *folder, int options);
    void print_l_option(char *file_folder, int options, int m);
    int is_folder_empty(char *folder);
#endif
