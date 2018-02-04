/*
** ls.h for ls.h in /root/Desktop/PSU_2016_my_ls/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Tue Nov 29 13:41:42 2016 Leo Lecherbonnier
** Last update Sun Dec  4 11:01:21 2016 Leo Lecherbonnier
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include "my.h"

struct dirent *readdir(DIR *dir);
void	check_repo(char* chemin);
void	read_repo(char* s, DIR* rep);
int	do_option(char *path, int option);
int	get_l_option(int ac, char **av);
int	get_r_option(int ac, char **av);
int	full_option(int ac, char **av);
int	check_flags(int ac, char **av);
int	check_after_minus(int ac, char **av, int i);
int	check_only_one(int ac, char **av);
int	check_before_flags(int ac, char **av);
int	check_option(int ac, char **av);
void	read_l_repo(DIR* rep, char* chemin);
void	check_l_repo(char* chemin);
void	check_r_repo(char* chemin);
void	my_print_tmp(char *tmp);
char	*str_cat(char *s1, char *s2);
unsigned int	print_block_allocated(char *dir_name);
void	handle_dir(struct dirent *d, char *path);
void	my_ls(char *path);

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);
