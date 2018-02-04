/*
** need4stek.h for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 16:29:13 2017 Monty Criel
** Last update Sun Jun  4 17:29:48 2017 Monty Criel
*/

#ifndef NFS_H

float		get_dist_avg(float *lidar, char dir);
float		get_lidar_avg(float *lidar);
char		**wordtab(char *str, char c);
char		*request(char *query);
void		print_tab(char **tab);
void		free_tab(char **tab);
void		debug(char *str);
void		print_lidar(float *lidar);
void		car_ai(float *lidar);
char		*copy(char *string);
char		*my_strcat(char *dest, char *src);
void		stop_car(char *str);

# endif /*NFS_H*/
