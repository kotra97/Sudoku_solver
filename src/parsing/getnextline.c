/*
** getnxtline.c for getnextline in /home/rousse_i/rendu/CPE/CPE_2016_getnextline
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Jan  4 12:52:12 2016 mathis rousselot
** Last update Sun Feb 28 00:16:13 2016 mathis rousselot
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*str_copy(char *str, char *buff, int nbr, int *curs_buff)
{
  char	*retrn;
  int	curs;

  curs = 0;
  if ((retrn = malloc(sizeof(char) * (nbr + 1) * 1 + 1)) == NULL)
    return (NULL);
  if (str != NULL)
    {
      while (curs != 15 * (nbr) && str[curs] != '\0')
	{
	  retrn[curs] = str[curs];
	  curs++;
	}
    }
  (*curs_buff) = 0;
  while ((*curs_buff) != 1)
    {
      retrn[curs] = buff[(*curs_buff)];
      curs++;
      (*curs_buff)++;
    }
  retrn[curs] = '\0';
  if (nbr != 0)
    free(str);
  return (retrn);
}

int		checker_buffer(char c)
{
  if (c != '\n' && c != ' ' && c != '-' && c != '|' && c != '\0')
    {
      if (c > '9' || c < '1')
	return (1);
    }
  return (0);
}

char		*main_read(char *buffer, char *retrn, int *curs_buff, int fd)
{
  int	nbr;
  int	check;

  nbr = 0;
  if (retrn != NULL)
    nbr++;
  while (42)
    {
      if ((check = (read(fd, buffer, 1))) == -1)
	return (NULL);
      buffer[check] = '\0';
      if (checker_buffer(buffer[0]) == 1)
	return (NULL);
      if (check == 0 || buffer == NULL)
	return (retrn);
      if ((retrn = str_copy(retrn, buffer, nbr, curs_buff)) == NULL)
	return (NULL);
      if ((*curs_buff) == check)
	(*curs_buff) = 0;
      else
	return (retrn);
      nbr++;
    }
}

char		*get_next_line(const int fd)
{
  char	buffer[2];
  int	curs_buff;
  char	*retrn;

  retrn = NULL;
  curs_buff = 0;
  retrn = main_read(buffer, retrn, &curs_buff, fd);
  return (retrn);
}
