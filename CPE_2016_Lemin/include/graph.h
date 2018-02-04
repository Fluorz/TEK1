/*
** graph.h for graph.h in /home/hugo/cours/Code/Semestre 2/Elementary programming in C (Part II)/CPE_2016_lemin_bootstrap/
**
** Made by Hugo Bleuzen
** Login   <hugo.bleuzen@epitech.eu>
**
** Started on  Thu Apr  6 11:14:10 2017 Hugo Bleuzen
** Last update Thu Apr  6 12:12:13 2017 Hugo Bleuzen
*/

#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct	s_link
{
  int			data;
  struct s_link	*next;
  struct s_link2	*voisin;
}			t_link;

typedef struct s_link2
{
  struct s_link *data;
  struct s_link2 *next;
}t_link2;

#endif
