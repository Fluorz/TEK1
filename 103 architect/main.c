/*
** main.c for calc.c in /home/lecherbonnier/103 architect/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Dec 20 14:26:47 2016 Leo Lecherbonnier
** Last update Tue Dec 20 14:26:51 2016 Leo Lecherbonnier
*/

#include "architecte.h"

int	main(int argc, char **argv)
{
  double	matrice[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  double	resultat[3];

  if (argc < 5)
    my_error("Too few arguments. Must enter 5 arguments minimum\nExecute ./man_103 to read the man");
  resultat[0] = atof(argv[1]);
  resultat[1] = atof(argv[2]);
  resultat[2] = 1;
  check_option(resultat, matrice, argv, argc);
  aff_mat(matrice);
  printf("(%s, %s) => (%.3f, %.3f)\n", argv[1], argv[2], resultat[0], resultat[1]);
  printf("\033[0;37m");
  return (0);
}
