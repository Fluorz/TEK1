/*
** print_debug.c for print_debug.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 16:42:51 2017 Leo Lecherbonnier
** Last update Mon Mar 13 11:37:14 2017 Leo Lecherbonnier
*/

#include "tetris.h"

void	print_debug(t_debug debug)
{
  char	buff[BUFF_SIZE];

  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : %s\n", debug.key_left);
  my_printf("Key Right : %s\n", debug.key_right);
  my_printf("Key Turn : %s\n", debug.key_turn);
  my_printf("Key Drop : %s\n", debug.key_drop);
  my_printf("Key Quit : %s\n", debug.key_quit);
  my_printf("Key Pause : %s\n", debug.key_pause);
  my_printf("Next : %s\n", debug.next);
  my_printf("Level : %d\n", debug.level);
  my_printf("Size : %s\n", debug.size);
  check_tetrimino();
  my_printf("Press any key to start Tetris\n");
  if (initTerm(false))
   return;
  my_memset(buff, 0, BUFF_SIZE);
  while (!buff[0])
    read(0, buff, BUFF_SIZE - 1);
  if (initTerm(false))
    return;
  map();
}

int			initTerm(bool mode)
{
  static struct termios old;
  struct termios	new;

  if (!mode)
    {
      if (ioctl(0, TCGETS, &old) == -1 || ioctl(0, TCGETS, &new) == -1)
	return (1);
      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VMIN] = 0;
      new.c_cc[VTIME] = 1;
      if (ioctl(0, TCSETS, &new) == -1)
	return (1);
      return (0);
    }
  else if (mode && ioctl(0, TCSETS, &old) == -1)
    return (1);
  return (0);
}

void	my_memset(void *mem, char c, int size)
{
  unsigned char	*str;

  str = mem;
  while (size--)
    str[size] = c;
}
