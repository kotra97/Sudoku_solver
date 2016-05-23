/*
** free_array.c for free_array in /home/rousse_i/rendu/CPE/Sudoki-Bi/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Feb 27 16:46:22 2016 mathis rousselot
** Last update Sat Feb 27 16:52:16 2016 mathis rousselot
*/

#include <stdlib.h>

void	free_array(int **tab)
{
  int	curs;

  curs = 0;
  while (curs != 9)
    {
      free(tab[curs]);
      curs++;
    }
  free(tab);
}
