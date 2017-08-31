/*
** option.c for option.c in /home/lecherbonnier/103 architect/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Dec 20 14:28:59 2016 Leo Lecherbonnier
** Last update Tue Dec 20 14:29:05 2016 Leo Lecherbonnier
*/

#include "architecte.h"

double	*check_option(double *resultat, double *matrice, char **argv, int argc)
{
  int	i;

  i = 3;
  while (i < argc)
    {
      if (argv[i][0] == 'T' && argv[i][1] == '\0')
        {
          if (argv[i + 1] == '\0' || argv[i + 2] == '\0')
            my_error("After option T or H, you must enter two numbers\nExecute ./man_103 to read the man");
          check_error_one(argv[i + 1]);
          check_error_one(argv[i + 2]);
          my_translation(&resultat[0], &matrice[0], argv, i);
          i = i + 3;
        }
      else if (argv[i][0] == 'H' && argv[i][1] == '\0')
        {
          if (argv[i + 1] == '\0' || argv[i + 2] == '\0')
            my_error("After option T or H, you must enter two numbers\nExecute ./man_103 to read the man");
          check_error_one(argv[i + 1]);
          check_error_one(argv[i + 2]);
          my_homothetie(&resultat[0], &matrice[0], argv, i);
          i = i + 3;
	}
      else if (argv[i][0] == 'R' && argv[i][1] == '\0')
	{
          if (argv[i + 1] == '\0')
            my_error("After option R or S, you must enter only one number\nExecute ./man_103 to read the man");
          check_error_two(argv[i + 1]);
          my_rotation(&resultat[0], &matrice[0], argv, i);
          i = i + 2;
        }
      else if (argv[i][0] == 'S' && argv[i][1] == '\0')
        {
          if (argv[i + 1] == '\0')
            my_error("After option R or S, you must enter only one number\nExecute ./man_103 to read the man");
          check_error_two(argv[i + 1]);
          my_symetrie(&resultat[0], &matrice[0], argv, i);
          i = i + 2;
        }
      else
        {
          printf("\033[01;31mWrong option. You can only enter options : T, H, R or S\nArgument number %d is not an option\nExecute ./man_103 to read the man\n", i);
          printf("\033[0;37m");
          exit (0);
        }
    }
  return (resultat);
}
