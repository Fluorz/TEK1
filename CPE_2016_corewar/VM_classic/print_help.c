/*
** print_help.c for print_help.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Mar 12 15:48:11 2017 Leo Lecherbonnier
** Last update Sun Mar 12 16:30:40 2017 Leo Lecherbonnier
*/

#include "vm.h"

/*
pour le -h
*/

void	print_help()
{
  my_printf("USAGE\n");
  my_printf("\t./corewar [-dump nbr_cycle] ");
  my_printf("[[-n prog_number] [-a load_address] prog_name] ...\n");
  my_printf("DESCRIPTION\n");
  my_printf("\t-dump nbr_cycle dumps the memory after");
  my_printf("the nbr_cycle execution (if the round isn’t\n");
	    my_printf("\t\t\talready over) with the");
  my_printf("following format: 32 bytes/line in\n\t\t\thexadecimal");
	   my_printf("(A0BCDEFE1DD3...)\n");
  my_printf("\t-n prog_number\tsets the next program’s number.");
  my_printf("By default, the first free number\n");
  my_printf("\t\t\tin the parameter order\n");
  my_printf("\t-a load_address sets the next program’s ");
  my_printf("loading address. When no address is\n");
  my_printf("\t\t\tspecified, optimize the addresses so that the ");
  my_printf("processes are as far\n");
  my_printf("\t\t\taway from each other as possible. ");
  my_printf("The addresses are MEM_SIZE modulo.\n");
  exit (0);
}
