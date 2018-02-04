/*
** my_atoi.c for matchstick in /home/byliarus/work/CPE/CPE_2016_matchstick/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 21 14:21:00 2017 John Doe
** Last update Tue Mar 21 10:21:14 2017 Antoine Briaux
*/

# define NEG(bol, res) ((bol) ? -(res) : (res))

int my_strlen (char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int my_pow(int a, int b)
{
  int i;
  int res;

  res = 1;
  i = 0;
  while (i < b)
  {
    res *= a;
    i++;
  }
  return (res);
}

int     my_atoi(char *str)
{
  int   res;
  int   i;
  int   bol;

  i = 0;
  bol = 0;
  if (str[0] == '-')
  {
    i = 1;
    bol = 1;
  }
  res = 0;
  while (str[i])
  {
    if (str[i] >= '0' && str[i] <= '9')
    res = res * 10 + str[i] - '0';
    else
    return (NEG(bol, res));
    i++;
  }
  return (NEG(bol, res));
}

float   my_atof(char *str)
{
  char  *point;
  int i;
  float res;

  i = 0;
  while (str[i] != '\0' && str[i] != '.')
    i++;
  point = &str[i + 1];
  res = (float)my_atoi(str) + (float)my_atoi(point) /
  (float)my_pow(10, my_strlen(point));
  return (res);
}
