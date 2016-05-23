/*
** main.c for main.c in /home/rousse_i/rendu/CPE/Sudoki-Bi/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Fri Feb 26 20:31:55 2016 mathis rousselot
** Last update Sun Feb 28 23:12:47 2016 mathis rousselot
*/

#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"

int	***malloc_tab(int nbr_su)
{
  int	curs;
  int	curs_2;
  int	***tab;

  curs = 0;
  if ((tab = malloc(sizeof(int **) * nbr_su)) == NULL)
    return (NULL);
  while (curs != nbr_su)
    {
      if ((tab[curs] = malloc(sizeof(int *) * 9)) == NULL)
	return (NULL);
      curs_2 = 0;
      while (curs_2 != 9)
	{
	  if ((tab[curs][curs_2] = malloc(sizeof(int) * 9)) == NULL)
	    return (NULL);
	  curs_2++;
	}
      curs++;
    }
  return (tab);
}

void	main_loop(int ***tab, int nbr_su)
{
  int   **tmp;
  int   curs;

  curs = 0;
  while (curs != nbr_su)
    {
      if (check_validity(tab[curs]) == 1)
	tab[curs][0][0] = -1;
      else if ((tmp = algo(tab[curs], 0, 0)) == NULL)
	tab[curs][0][0] = -1;
      else
	tab[curs] = tmp;
      print_tab(tab[curs], curs);
      free_array(tab[curs]);
      curs++;
    }
}

int	main()
{
  int	***tab;
  int	nbr_su;
  char	*str;

  if ((str = get_next_line(0)) == NULL)
    {
      fprintf(stderr, "MAP ERROR\n\n");
      return (1);
    }
  if ((nbr_su = check_table(str)) == -1)
    {
      fprintf(stderr, "MAP ERROR\n\n");
      return (1);
    }
  if ((tab = malloc_tab(nbr_su)) == NULL)
    return (1);
  get_table(tab, str, nbr_su);
  main_loop(tab, nbr_su);
  free(tab);
  free(str);
  return (0);
}
