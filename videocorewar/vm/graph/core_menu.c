/*
** core_menu.c for core menu in /home/cherkaoui/Bureau/Core war
** 
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
** 
** Started on  Thu Mar 30 07:47:29 2017 Cherkaoui
** Last update Thu Apr 20 18:51:41 2017 abdel cherkaoui
*/

#include "../graph.h"

void            print_effect(t_my_framebuffer *fb)
{
  t_my_square	pos;
  sfColor       colorch;
  int           i;

  i = 0;
  while (i != 10)
    {
      pos.x0 = 100 + (rand() % 550);
      pos.y0 = 300 + (rand() % 350);
      pos.x1 = pos.x0 + 10;
      pos.y1 = pos.y0 + 10;
      colorch.r = 204;
      colorch.g = 51;
      colorch.b = 204;
      colorch.a = 90;
      draw_sq(fb, pos, colorch);
      i++;
    }
}

int     my_strlenn(char *str)
{
  int   i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char    *my_strdupp(char *dest, char *src)
{
  int   i;

  if(src == NULL)
    return (NULL);
  i = 0;
  dest = malloc(sizeof(char) * my_strlenn(src) + 1);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

// FC_base ANTI MONTY

char    *my_strcatt(char *str1, char *str2)
{
  char  *newstr;
  int   len;
  int   i;
  int   s;

  i = 0;
  s = 0;
  newstr = NULL;
  if (str1 == NULL || str2 == NULL)
    {
      if (str1 == NULL && str2 != NULL)
	newstr = my_strdupp(newstr, str2);
      else if (str2 == NULL && str1 != NULL)
	newstr = my_strdupp(newstr, str2);
      return (newstr);
    }
  else
    {
      len = my_strlenn(str1) + my_strlenn(str2);
      newstr = malloc(sizeof(char) * len + 2);
      if (newstr == NULL)
	return (NULL);
      while (str1[i] != '\0')
	{
	  newstr[i] = str1[i];
	  i = i + 1;
	}
      while (str2[s] != '\0')
	{
	  newstr[i] = str2[s];
	  i = i + 1;
	  s = s + 1;
	}
      newstr[i] = '\0';
      return (newstr);
    }
}

int     check_extention(char *str, char *fin)
{
  int   len;
  int   x;
  int	v;

  v = my_strlenn(fin);

  len = -1;
  x = 0;
  if (str != NULL)
    while (str[++len] != '\0');
  else
    return (1);
  if (len >= v)
    {
      while (str[len - v + x] != '\0')
	{
	  if (str[len - v + x] != fin[x])
	    return (1);
	  x++;
	}
      return (0);
    }
  else
    return (1);
}

//// SELECT CHAMPION

//give liste of champions

t_my_core	read_files(t_my_core cr)
{
  DIR           *dir;
  struct dirent *read;
  int           i;
  int           i2;

  i = 0;
  i2 = 0;
  dir = opendir("./champ");
  while ((read = readdir(dir)))
    if (read->d_name[0] != '.')
      {
	if (check_extention(read->d_name , ".cor") == 0)
	  {
	    cr.listcor[i] = my_strdupp(cr.listcor[i] , read->d_name);
	    cr.pathcor[i] = my_strdupp(cr.pathcor[i] , read->d_name);
	    printf("%s\n",cr.pathcor[i]);
	    cr.pathcor[i] = my_strcatt("champ/", cr.pathcor[i]);
	    i = i + 1;
	  }
	else if (check_extention(read->d_name , ".s") == 0)
	  {
	    cr.lists[i2] = my_strdupp(cr.lists[i2] , read->d_name);
	    cr.paths[i2] = my_strdupp(cr.paths[i2] , read->d_name);
	    printf("[S] %s\n",cr.paths[i2]);
	    cr.paths[i2] = my_strcatt("champ/", cr.paths[i2]);
	    i2 = i2 + 1;
	  }
      }
  cr.listcor[i] = NULL;
  cr.pathcor[i] = NULL;
  cr.lists[i2] = NULL;
  cr.paths[i2] = NULL;
  closedir(dir);
  return (cr);
}

t_my_core        give_files(t_my_core cr)
{
  DIR           *dir;
  struct dirent *read;
  int           nbfiles;
  int           nbfiles2;

  nbfiles = 0;
  nbfiles2 = 0;
  dir = opendir("./champ");
  if (dir == NULL)
    exit(84);
  else
    while ((read = readdir(dir)))
      if (read->d_name[0] != '.')
	{
	  if (check_extention(read->d_name , ".cor") == 0)
	    nbfiles = nbfiles + 1;
	  else if (check_extention(read->d_name , ".s") == 0)
	    nbfiles2 = nbfiles2 + 1;
	}
  closedir(dir);
  cr.nbcor = nbfiles;
  cr.listcor = malloc(sizeof(char *) * nbfiles * 100);
  cr.pathcor = malloc(sizeof(char *) * nbfiles * 100);
  cr.lists = malloc(sizeof(char *) * nbfiles2 * 100);
  cr.paths = malloc(sizeof(char *) * nbfiles2 * 100);
  cr = read_files(cr);
  return (cr);
}

///KEY SELECT
t_my_core key_board_select(t_my_core cr)
{
  static int	c1 = -1;
  static int	c2 = -1;
  static int	c3 = -1;
  static int	c4 = -1;
  
  if (cr.event.key.code == sfKeyUp)
    {
      sfMusic_play(cr.shot);
      if (cr.start == 0)
	cr.start = 58 * 5;
      else
	cr.start = cr.start - 58;
    }
  else if (cr.event.key.code == sfKeyReturn) // VALIDATE PERSONAGE
    {
      if (cr.start == (58 * 4))
	{
	  cr.ac = 1;
	  cr.newav[0] = my_strdupp(cr.newav[0], cr.champ1);
	  cr.newav[1] = my_strdupp(cr.newav[1], cr.champ2);
	  cr.newav[2] = my_strdupp(cr.newav[2], cr.champ3);
	  cr.newav[3] = my_strdupp(cr.newav[3], cr.champ4);
	  cr.newav[4] = NULL;
	  if (cr.champ1 != NULL)
	    cr.ac = cr.ac + 1;
	  if (cr.champ2 != NULL)
	    cr.ac = cr.ac + 1;
	  if (cr.champ3 != NULL)
	    cr.ac = cr.ac + 1;
	  if (cr.champ4 != NULL)
	    cr.ac = cr.ac + 1;
	  cr.fase = 2;
	}
    }
  else if (cr.event.key.code == sfKeyRight)     ///RIGHT
    {
      if (cr.start == 0)
	{
	  if(cr.pathcor[c1 + 1] != NULL)
	    {
	      c1++;
	      cr.champ1 = my_strdupp(cr.champ1, cr.pathcor[c1]);
	      sfText_setString(cr.ch1, cr.listcor[c1]);
	    }
	  else
	    c1 = -1;
	}
      else if (cr.start == 58)
	{
	  if(cr.pathcor[c2 + 1] != NULL)
	    {
	      c2++;
	      cr.champ2 = my_strdupp(cr.champ2, cr.pathcor[c2]);
	      sfText_setString(cr.ch2, cr.listcor[c2]);
	    }
	  else
	    c2 = -1;
	}
      else if (cr.start == 58 * 2)
	{
	  if(cr.pathcor[c3 + 1] != NULL)
	    {
	      c3++;
	      cr.champ3 = my_strdupp(cr.champ3, cr.pathcor[c3]);
	      sfText_setString(cr.ch3, cr.listcor[c3]);
	    }
	  else
	    c3 = -1;
	}
      else if (cr.start == 58 * 3)
	{
	  if(cr.pathcor[c4 + 1] != NULL)
	    {
	      c4++;
	      cr.champ4 = my_strdupp(cr.champ4, cr.pathcor[c4]);
	      sfText_setString(cr.ch4, cr.listcor[c4]);
	    }
	  else
	    c4 = -1;
	}
    }
  else if (cr.event.key.code == sfKeyLeft)     ///RIGHT
    {
      if (cr.start == 0)
	{
	  if(c1 > 0)
	    {
	      c1--;
	      cr.champ1 = my_strdupp(cr.champ1, cr.pathcor[c1]);
	      sfText_setString(cr.ch1, cr.listcor[c1]);
	    }
	  else
	    c1 = cr.nbcor;
	}
      else if (cr.start == 58)
	{
	  if (c2 > 0)
	    {
	      c2--;
	      cr.champ2 = my_strdupp(cr.champ2, cr.pathcor[c2]);
	      sfText_setString(cr.ch2, cr.listcor[c2]);
	    }
	  else
	    c2 = cr.nbcor;
	}
      else if (cr.start == 58 * 2)
	{
	  if(c3 > 0)
	    {
	      c3--;
	      cr.champ3 = my_strdupp(cr.champ3, cr.pathcor[c3]);
	      sfText_setString(cr.ch3, cr.listcor[c3]);
	    }
	  else
	    c3 = cr.nbcor;
	}
      else if (cr.start == 58 * 3)
	{
	  if(c4 > 0)
	    {
	      c4--;
	      cr.champ4 = my_strdupp(cr.champ4, cr.pathcor[c4]);
	      sfText_setString(cr.ch4, cr.listcor[c4]);
	    }
	  else
	    c4 = cr.nbcor;
	}
    }
  return (cr);
}

t_my_core       print_select(t_my_core cr)
{
  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	{
	  if (cr.event.key.code == sfKeyDown)
	    if (cr.start == 58 * 5)
	      cr.start = 0;
	    else
	      cr.start = cr.start + 58;
	  else
	    cr = key_board_select(cr);
	}
      sfMusic_play(cr.shot);
    }
  sfRenderWindow_drawSprite(cr.window, cr.select, NULL);
  sfSprite_setPosition(cr.cours2, (sfVector2f){859, 283 + cr.start});
  //text
  sfRenderWindow_drawText(cr.window, cr.ch1, NULL);
  sfRenderWindow_drawText(cr.window, cr.ch2, NULL);
  sfRenderWindow_drawText(cr.window, cr.ch3, NULL);
  sfRenderWindow_drawText(cr.window, cr.ch4, NULL);
  
  sfRenderWindow_drawSprite(cr.window, cr.cours2, NULL);
  print_effect(cr.framebuffer);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}
// END SELECT CHAMPION

t_my_core key_board_menu(t_my_core cr)
{
  if (cr.event.key.code == sfKeyUp)
    {
      sfMusic_play(cr.shot);
      if (cr.start == 0)
	cr.start = 58 * 4;
      else
	cr.start = cr.start - 58;
    }
  else if (cr.event.key.code == sfKeyReturn)
    {
      if (cr.start == 0)
	cr.fase = 1;
      else if (cr.start == 58)
	cr.fase = 2;
      else if (cr.start == 58 * 3)
	cr.fase = 4;
      else if (cr.start == (58 * 4))
	cr.fase = 5;
    }
  return (cr);
}

t_my_core       print_menu(t_my_core cr)
{
  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	{
	  if (cr.event.key.code == sfKeyDown)
	    if (cr.start == 58 * 4)
	      cr.start = 0;
	    else
	      cr.start = cr.start + 58;
	  else
	    cr = key_board_menu(cr);
	}
      sfMusic_play(cr.shot);
    }
  sfRenderWindow_drawSprite(cr.window, cr.menu, NULL);
  sfSprite_setPosition(cr.cours, (sfVector2f){899, 290 + cr.start});
  sfRenderWindow_drawSprite(cr.window, cr.cours, NULL);
  print_effect(cr.framebuffer);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}

t_my_core       print_converter(t_my_core cr)
{
  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	{
	  if (cr.event.key.code == sfKeyEscape)
	    {
	      cr.fase = 0;
	    }
	}
    }
  sfRenderWindow_drawSprite(cr.window, cr.converter, NULL);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}

t_my_core       print_credit(t_my_core cr)
{
  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	{
	  if (cr.event.key.code == sfKeyEscape)
	    {
	      cr.fase = 0;
	    }
	}
    }
  print_effect(cr.framebuffer);
  sfRenderWindow_drawSprite(cr.window, cr.credit, NULL);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}
