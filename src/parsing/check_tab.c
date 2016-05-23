/*
** check_tab.c for checktab in /home/rousse_i/rendu/CPE/Sudoki-Bi/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Fri Feb 26 22:27:06 2016 mathis rousselot
** Last update Sun Feb 28 15:13:55 2016 mathis rousselot
*/

#include <stdio.h>

int     check_interior(int cont, char cara, int nbr)
{
  if (((cont >= 230 * nbr + nbr && cont <= 230 * nbr + 19 + nbr) ||
       (cont <= 230 * (nbr + 1) + nbr && cont >= 230 * (nbr + 1) - 19  + nbr))
      && cont % 21 != 20)
    {
      if (cara != '-')
	return (1);
    }
  else if (cara != ' ' && cont % 21 % 2 == 1 && cont % 21 != 19)
    return (1);
  else if (cara != ' ' && cara < '0' && cara > '9')
    return (1);
  else if (cont % 21 == 20 && cara != '\n')
    return (1);
  return (0);
}

int     check_table(char *str)
{
  int   cont;
  int   nbr;

  cont = 0;
  nbr = 0;
  while (str[cont] != '\0')
    {
      if ((cont % 21 == 19 || cont % 21 == 0))
        {
	  if (str[cont] != '|')
	    return (-1);
        }
      else if (check_interior(cont, str[cont], nbr) == 1)
        return (-1);
      if (cont == 230 + 230 * nbr + nbr)
        nbr++;
      cont++;
    }
  if (cont != 230 * nbr + nbr)
    return (-1);
  return (nbr);
}
