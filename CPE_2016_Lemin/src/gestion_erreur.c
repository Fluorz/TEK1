/*
** gestion_erreur.c for gestion_erreur.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Apr 24 11:32:58 2017 Leo Lecherbonnier
** Last update Jan Apr 30 18:23:35 2017
*/

#include "open_file.h"

int	check_before(t_info *info)
{
  if (info->file[0][0] < '0' || info->file[0][0] > '9')
    return (FAILURE);
  info->nb_ant = my_getnbr(info->file[0]);
  if (info->nb_ant <= 0)
    return (FAILURE);
  print_ant(info->nb_ant);
  return (SUCCESS);
}

int	gestion_erreur(t_info	*info)
{
  int	one = 0;
  int	boole = 0;
  int	j = 0;

  if (check_before(info) == FAILURE)
    return (FAILURE);
  j++;
  while (info->file[j])
    {
      if (my_strcmp("##start", info->file[j]) == 0)
	  boole++;
      else if (my_strcmp("##end", info->file[j]) == 0)
	  boole = boole + 10;
      else if (check_erreur(info, &one, j) == 1)
	return (1);
      my_printf("%s\n", info->file[j]);
      j++;
    }
  if (boole == 11)
    return (SUCCESS);
  return (FAILURE);
}

int	check_erreur(t_info *info, int *one, int j)
{
  if (info->file[j][1] == '-' && *one == 0)
    {
      my_printf("#tunnels\n");
      *one = *one + 1;
    }
  return (0);
}

void	print_ant(int ant)
{
  my_printf("#number_of_ants\n");
  my_printf("%d\n", ant);
  my_printf("#rooms\n");
}
