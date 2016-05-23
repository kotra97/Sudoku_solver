/*
** algo.c for algo in /home/rousse_i/rendu/CPE/Sudoki-Bi
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Feb 27 17:29:38 2016 mathis rousselot
** Last update Sun Feb 28 16:09:04 2016 mathis rousselot
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sudoku.h"

int     check_next_nbr(int nbr)
{
  int   curs;
  int   power;

  curs = 8;
  if (nbr == 0)
    return (0);
  while (curs != -1)
    {
      power = pow(10, curs);
      if (nbr / power == 1)
        return (curs + 1);
      curs--;
    }
  return (curs);
}

int	check_error(int **tab, int **prob)
{
  int	curs;
  int	curs_2;

  curs = 0;
  while (curs != 9)
    {
      curs_2 = 0;
      while (curs_2 != 9)
	{
	  if (tab[curs][curs_2] == 0 && prob[curs][curs_2] == 0)
	    return (1);
	  curs_2++;
	}
      curs++;
    }
  return (0);
}

int	**loop(int act, int curs, int curs_2, int **tab)
{
  int	**ret;
  int	nbr;

  while (act != 0)
    {
      nbr = check_next_nbr(act);
      if (nbr == -1)
	{
	  tab[curs][curs_2] = 0;
	  return (NULL);
	}
      tab[curs][curs_2] = nbr;
      if ((ret = algo(tab, curs, curs_2)) == NULL)
	act -= pow(10, nbr - 1);
      if (ret != NULL)
	return (ret);
    }
  tab[curs][curs_2] = 0;
  return (NULL);
}

int	**algo(int **tab, int curs, int curs_2)
{
  int	**proba;
  int	act;

  while (curs != 9 && tab[curs][curs_2] != 0)
    {
      if (tab[curs][curs_2] != 0)
	curs_2++;
      if (curs_2 == 9)
	{
	  curs++;
	  curs_2 = 0;
	}
    }
  if (curs == 9)
    return (tab);
  if ((proba = sudosolve(tab)) == NULL)
    return (NULL);
  if (check_error(tab, proba) == 1)
    {
      free_array(proba);
      return (NULL);
    }
  act = proba[curs][curs_2];
  free_array(proba);
  return (loop(act, curs, curs_2, tab));
}
