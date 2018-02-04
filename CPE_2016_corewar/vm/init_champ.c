/*
** fc_check_tetrimino.c for check tetrimino in /home/cherkaoui/PSU_2016_tetris/fc_abdel
**
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
**
** Started on  Mon Feb 27 16:08:02 2017 Cherkaoui
** Last update Sun Apr  2 16:44:09 2017 Leo Lecherbonnier
*/

#include <fcntl.h>
#include "vm.h"

int	my_op_cmp(char *str, char *elem)
{
  int	len = 0;

  len = my_strlen(str) - 1;
  if (str[len] != elem[3])
    return (FAILURE);
  if (str[len - 1] != elem[2])
    return (FAILURE);
  if (str[len - 2] != elem[1])
    return (FAILURE);
  if (str[len - 3] != elem[0])
    return (FAILURE);
  return (SUCCESS);
}

int	my_open_file(char *file, int *fd)
{
  if ((*fd = open(file, O_RDONLY)) != -1)
    return (SUCCESS);
  return (FAILURE);
}

static int my_reader_header(char *file, const int fd, t_champ *champ, int id)
{
  long unsigned int	nb_read = 0;

  champ[id].header = malloc(sizeof(t_hd));
  nb_read = read(fd, champ[id].header, sizeof(t_hd));
  if (nb_read <= 0 || nb_read != sizeof(t_hd))
    return (my_putstr("Error : Corrupted header\n"));
  CONVERT(champ[id].header->prog_size);
  CONVERT(champ[id].header->magic);
   if (champ[id].header->magic != COREWAR_EXEC_MAGIC)
    return (my_putstr("Error : Wrong magic code\n"));
  return (SUCCESS);
}

int	my_reader_code(char *file, int fd, t_champ *champ, int id)
{
  unsigned short		nb_read;
  int								len;

  len = champ[id].header->prog_size + 2;
  if (!(champ[id].code = malloc(sizeof(char) * len)))
    {
      my_putstr("Can alloc memory for the champ code");
      return (FAILURE);
    }
  nb_read = read(fd, champ[id].code, champ[id].header->prog_size);
  if (nb_read <= 0 || nb_read != champ[id].header->prog_size)
    return (my_putstr("Error : Invalid program size\n"));
  if ((champ[id].name = malloc(sizeof (char) * PROG_NAME_LENGTH + 1)) == NULL)
    return (FAILURE);
  champ[id].name = file;
  return (SUCCESS);
}

t_champ	*put_champs(t_champ *champs, char **av, int ac)
{
  int	fd = 0;
  int	i = 0;
  int	nbr_champs = 0;

  if ((champs = malloc(sizeof(t_champ) * 4)) == NULL)
    exit(my_putstr("Problem with memory champs"));
  while (av[i])
    {
      if ((my_op_cmp(av[i], ".cor") != SUCCESS))
	exit(my_putstr("Wrong File ! expected: .cor\n"));
  my_printf("%s\n", av[i]);
      if ((my_open_file(av[i], &fd)) != SUCCESS)
	exit(my_printf("Can't open this file : %s\n", av[i]));
      if ((my_reader_header(av[i], fd, champs, nbr_champs)) != SUCCESS)
	exit(my_putstr("Problem with header\n"));
      if ((my_reader_code(av[i], fd, champs, nbr_champs)) != SUCCESS)
	exit(my_putstr("Problem with code\n"));
      champs[nbr_champs].alive = ALIVE;
      nbr_champs++;
      i++;
      close(fd);
    }
  champs->nbr_player = nbr_champs;
  return (champs);
}
