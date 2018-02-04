/*
** pivot.c for raytracer1 in /home/byliarus/work/Graph/raytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Mar  9 18:28:11 2017 John Doe
** Last update Fri Mar 10 18:03:11 2017 John Doe
*/

void div_coef(float **inv, float **matrice, int size)
{
  int i;
  int j;

  i = -1;
  while (++i < size)
  {
    j = -1;
      while (++j < size)
        inv[i][j] /= matrice[i][i];
  }
}

void pivot(float **matrice, float **inv, int size)
{
  int i;
  int j;
  int k;
  int l;

  k = -1;
  while (++k < size)
    {
      i = -1;
      while (++i < size)
      {
        if (i == k)
          i++;
        if (i == size)
          return;
          j = -1;
          l = matrice[i][k];
          while (++j < size)
          {
            matrice[i][j] = l * matrice[k][j] - matrice[k][k] * matrice[i][j];
            inv[i][j] = l * inv[k][j] - matrice[k][k] * inv[i][j];
          }
      }
    }
    div_coef(inv, matrice, size);
}
