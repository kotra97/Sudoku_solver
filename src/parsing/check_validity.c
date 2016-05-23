/*
** check_validity.c for check_error in /home/rousse_i/rendu/CPE/Sudoki-Bi/src/parsing
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sun Feb 28 15:28:43 2016 mathis rousselot
** Last update Sun Feb 28 15:51:09 2016 mathis rousselot
*/

#include <stdio.h>

int	square(int **tab, int curs, int curs_2)
{
  int	tmp;
  int	tmp_2;
  int	check;
  int	check_2;

  tmp = (curs / 3) * 3;
  tmp_2 = (curs_2 / 3) * 3;
  check = 0;
  while (check != 3)
    {
      check_2 = 0;
      while (check_2 != 3)
	{
	  if (tab[curs][curs_2] == tab[tmp + check][tmp_2 + check_2]
	      && tmp + check != curs && tmp_2 + check_2 != curs_2)
	    return (1);
	  check_2++;
	}
      check ++;
    }
  return (0);
}

int	existence(int **tab, int curs, int curs_2)
{
  int	tmp;
  int	tmp_2;

  tmp = 0;
  tmp_2 = curs_2;
  while (tmp != 9)
    {
      if (tab[curs][curs_2] == tab[tmp][tmp_2] && tmp != curs)
	return (1);
      tmp++;
    }
  tmp = curs;
  tmp_2 = 0;
  while (tmp_2 != 9)
    {
      if (tab[curs][curs_2] == tab[tmp][tmp_2] && tmp_2 != curs_2)
	return (1);
      tmp_2++;
    }
  return (square(tab, curs, curs_2));
}

int	check_validity(int **tab)
{
  int	curs;
  int	curs_2;

  curs = 0;
  while (curs != 9)
    {
      curs_2 = 0;
      while (curs_2 != 9)
	{
	  if (tab[curs][curs_2] != 0)
	    if (existence(tab, curs, curs_2) == 1)
	      return (1);
	  curs_2++;
	}
      curs++;
    }
  return (0);
}
