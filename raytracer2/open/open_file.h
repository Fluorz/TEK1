/*
** open_file.h for open_file.h in /home/lecherbonnier/Projet/raytracer2/open/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun May 28 20:52:37 2017 Leo Lecherbonnier
** Last update Jan May 28 22:44:41 2017
*/

#include <unistd.h>
#include <stdlib.h>
#include "raytracer.h"

int	my_strlen(char *src);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
char	**get_tab(char **av);
t_object *init_struct();
int	f_ca(char *argument, char *where);
int	add_it(t_object **object, t_object *node);
char		**my_str_to_wordtab(char *str, char separe);
