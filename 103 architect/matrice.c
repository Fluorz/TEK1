/*
** matrice.c for matrice.c in /home/lecherbonnier/103 architect/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Dec 20 14:27:36 2016 Leo Lecherbonnier
** Last update Tue Dec 20 14:27:42 2016 Leo Lecherbonnier
*/

#include "architecte.h"

void	aff_mat(double *matrice)
{
  int	i;
  int	j;

  i = 0;
  printf("\t");
  while (i < 9)
    {
      printf("%.3f", matrice[i]);
      i++;
      if (i % 3 == 0)
	{
        printf("\n");
	if (j < 2)
	  printf("\t");
	j++;
	}
      else
        printf("  ");
    }
}

double	*mult_mat(double *m, double *m2)
{
  double	m3[9] = {m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]};

  m[0] = m3[0] * m2[0] + m3[1] * m2[3] + m3[2] * m2[6];
  m[1] = m3[0] * m2[1] + m3[1] * m2[4] + m3[2] * m2[7];
  m[2] = m3[0] * m2[2] + m3[1] * m2[5] + m3[2] * m2[8];
  m[3] = m3[3] * m2[0] + m3[4] * m2[3] + m3[5] * m2[6];
  m[4] = m3[3] * m2[1] + m3[4] * m2[4] + m3[5] * m2[7];
  m[5] = m3[3] * m2[2] + m3[4] * m2[5] + m3[5] * m2[8];
  m[6] = m3[6] * m2[0] + m3[7] * m2[3] + m3[8] * m2[6];
  m[7] = m3[6] * m2[1] + m3[7] * m2[4] + m3[8] * m2[7];
  m[8] = m3[6] * m2[2] + m3[7] * m2[5] + m3[8] * m2[8];
  return (m);
}

double	*fill_mat_homo(double *matrice_homothetie, double Hx, double Hy)
{
  matrice_homothetie[0] = Hx;
  matrice_homothetie[1] = 0;
  matrice_homothetie[2] = 0;
  matrice_homothetie[3] = 0;
  matrice_homothetie[4] = Hy;
  matrice_homothetie[5] = 0;
  matrice_homothetie[6] = 0;
  matrice_homothetie[7] = 0;
  matrice_homothetie[8] = 1;
  return (matrice_homothetie);
}

double	*fill_mat_rot(double *matrice_rotation, double Rx, double Ry)
{
  matrice_rotation[0] = Rx;
  matrice_rotation[1] = -Ry;
  matrice_rotation[2] = 0;
  matrice_rotation[3] = Ry;
  matrice_rotation[4] = Rx;
  matrice_rotation[5] = 0;
  matrice_rotation[6] = 0;
  matrice_rotation[7] = 0;
  matrice_rotation[8] = 1;
  return (matrice_rotation);
}

double	*fill_mat_sym(double *matrice_symetrie, double Sx, double Sy)
{
  matrice_symetrie[0] = Sx;
  matrice_symetrie[1] = Sy;
  matrice_symetrie[2] = 0;
  matrice_symetrie[3] = Sy;
  matrice_symetrie[4] = -Sx;
  matrice_symetrie[5] = 0;
  matrice_symetrie[6] = 0;
  matrice_symetrie[7] = 0;
  matrice_symetrie[8] = 1;
  return (matrice_symetrie);
}
