/*
** my_getnbr.c for get_nbr in /home/pion_b/PSU_2016_my_printf/lib/my
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Thu Nov 17 15:09:17 2016 Virgile
** Last update Sun Jan 22 10:07:28 2017 Virgile
*/

#include "my.h"

int	get_sign(char *str)
{
  int	i;
  int	sign;

  i = 0;
  sign = 0;
  while (str[i] != '0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	sign = sign + 1;
      i++;
    }
  if ((sign % 2) != 0)
    return (i);
  else
    return (0);
}

int	start(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    i++;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    i++;
  return (i);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	power;

  nb = 0;
  i = 0;
  power = 1;
  i = start(str) - 1;
  while (i >= 0 && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb + (power * (str[i] - '0'));
      i = i - 1;
      power = power * 10;
    }
  if (get_sign(str) > 0)
    nb = -nb;
  return (nb);
}
