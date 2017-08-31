/*
** architecte.h for architecte in /home/lecherbonnier/103 architect/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Dec 20 14:25:22 2016 Leo Lecherbonnier
** Last update Tue Dec 20 14:36:53 2016 Leo Lecherbonnier
*/

#ifndef ARCHITECTE_H_
#	define ARCHITECTE_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fenv.h>
#include <math.h>

double	*check_option(double *, double *, char **, int);
double	*my_translation(double *, double *, char **, int);
double	*my_homothetie(double *, double *, char **, int);
double	*my_rotation(double *, double *, char **, int);
double	*my_symetrie(double *, double *, char **, int);
double	*mult_mat(double *, double *);
double	*fill_mat_rot(double *, double, double);
double	*fill_mat_sym(double *, double, double);
void	aff_mat(double *);
void	my_putchar(char);
void	my_putstr(char *);
void	my_error(char *);
void	check_error_one(char *);
void	check_error_two(char *);
int	my_str_isnum(char *);

#endif /* !ARCHITECTE_H_ */
