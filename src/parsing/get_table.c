/*
** get_table.c for get_table.c in /home/rousse_i/rendu/CPE/Sudoki-Bi/src
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Sat Feb 27 10:42:06 2016 mathis rousselot
** Last update Sat Feb 27 14:34:14 2016 mathis rousselot
*/

typedef struct  s_curs
{
  int           curs;
  int           curs_2;
  int           curs_3;
}               t_curs;

int     check_nbr(int ***tab, char carac, t_curs *curs, int nbr_su)
{
  if (carac <= '9' && carac >= '0')
    {
      tab[curs->curs][curs->curs_2][curs->curs_3] = carac - '0';
      curs->curs_3++;
    }
  else
    {
      tab[curs->curs][curs->curs_2][curs->curs_3] = 0;
      curs->curs_3++;
    }
  if (curs->curs_3 == 9)
    {
      curs->curs_3 = 0;
      curs->curs_2++;
    }
  if (curs->curs_2 == 9)
    {
      curs->curs_2 = 0;
      curs->curs++;
    }
  if (curs->curs == nbr_su)
    return (1);
  return (0);
}

int             get_table(int ***tab, char *str, int nbr_su)
{
  t_curs        curs;
  int           cont;
  int		nbr;

  cont = 0;
  curs.curs = 0;
  curs.curs_2 = 0;
  curs.curs_3 = 0;
  nbr = 0;
  while (str[cont] != '\0')
    {
      if ((cont >= 230 * nbr + 19 + nbr && cont <= 230 * (nbr + 1) - 19  + nbr)
	  && cont % 21 <= 18 && cont % 21 % 2 != 1 && cont % 21 != 0)
	if (check_nbr(tab, str[cont], &curs, nbr_su) == 1)
	  return (1);
      if (cont == 230 + 230 * nbr + nbr)
        nbr++;
      cont++;
    }
  return (0);
}
