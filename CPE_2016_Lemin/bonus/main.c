/*
** main.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Apr 19 14:35:56 2017 Monty Criel
** Last update Sun Apr 30 23:09:12 2017 Monty Criel
*/

#include <stdlib.h>
#include <pthread.h>
#include "lemin.h"
#include "my.h"

t_gui		*init_gui(t_gui *gui)
{
  sfVector2f	pos;
  sfFloatRect	rectangle;

  gui = malloc(sizeof(t_gui));
  if (gui == NULL)
    return (NULL);
  gui->window = create_window("Lemin Window", WIDTH, HEIGHT);
  gui->sprite = create_sprite();
  gui->texture = create_texture(WIDTH, HEIGHT);
  sfSprite_setTexture(gui->sprite, gui->texture, sfTrue);
  gui->bg_sprite = create_sprite();
  gui->bg_texture = sfTexture_createFromFile("images/background.jpg", NULL);
  sfSprite_setTexture(gui->bg_sprite, gui->bg_texture, sfTrue);
  gui->room_texture = sfTexture_createFromFile("images/circle.jpg", NULL);
  gui->ant_texture = sfTexture_createFromFile("images/ant.png", NULL);
  rectangle.left = 0;
  rectangle.top = 0;
  rectangle.width = WIDTH;
  rectangle.height = HEIGHT;
  gui->pos.x = 0;
  gui->pos.y = 0;
  gui->view = sfView_createFromRect(rectangle);
  sfRenderWindow_setView(gui->window, gui->view);
  gui->fb = my_frame_buffer_create(WIDTH, HEIGHT);
  return (gui);
}

t_lemin	*init_lemin(char **tab)
{
  t_lemin	*lemin;
  t_list	*list;

  if ((lemin = malloc(sizeof(t_lemin))) == NULL)
    return (NULL);
  lemin->ants = my_getnbr(tab[1]);
  lemin->tunnels = get_tunnels(tab);
  lemin->moves = get_moves(tab);
  lemin->total = 0;
  list = malloc(sizeof(t_list));
  if (list == NULL)
    return (NULL);
  list->head = NULL;
  list = create_list(list, tab);
  if (list == NULL)
    return (NULL);
  lemin->list = list;
  return (lemin);
}

int		main(int argc, char **argv)
{
  char		**tab;
  t_lemin	*lemin;
  t_gui	*gui;
  t_args	args;
  pthread_t	thread1;

  if (argc != 2)
    return (84);
  tab = get_data(argv[1]);
  gui = init_gui(gui);
  lemin = init_lemin(tab);
  args.lemin = lemin;
  args.gui = gui;
  load_lemin(lemin, gui);
  pthread_create(&thread1, NULL, (void*)window_loop, &args);
  launch_lemin(lemin);
  return (0);
}
