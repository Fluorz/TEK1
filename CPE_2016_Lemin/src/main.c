/*
** main.c for main.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Apr 20 13:01:51 2017 Leo Lecherbonnier
** Last update Jan Apr 30 22:20:23 2017
*/

#include "open_file.h"

int	main()
{
  int	nb_ants;
  t_info	*info;

  if ((info = malloc(sizeof(t_info))) == NULL)
    return (1);
  if ((info = get_file()) == NULL)
    return (84);
  if ((info->file = bad_epure(info)) == NULL)
    return (84);
  if (gestion_erreur(info) == FAILURE)
    return (84);
  if ((info->file = epure(info)) == NULL)
    return (84);
  nb_ants = my_getnbr(info->file[0]);
  if ((info->file = tri_data(info->file)) == NULL)
    return (84);
  if ((check_room_and_co(info->file)) != SUCCESS)
    return (84);
  if ((check_coordonate(info->file)) != SUCCESS)
    return (84);
  if ((launch_resolution(info, nb_ants)) != SUCCESS)
    return (84);
  return (0);
}
