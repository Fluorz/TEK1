/*
** controller.h for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/bonus/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Jun  4 20:24:03 2017 Monty Criel
** Last update Sun Jun  4 20:31:26 2017 Monty Criel
*/

#ifndef CONTROLLER_H

#include <SFML/Graphics.h>

typedef struct	s_controller
{
  sfVector2f		joy1;
  sfVector2f		joy2;
  float		rt_button;
}			t_controller;

char	*request(char *query);
void	debug(char *str);

# endif /*CONTROLLER_H*/
