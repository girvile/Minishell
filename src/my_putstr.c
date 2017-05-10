/*
** my_putstr.c for my_putstr in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan 16 14:09:03 2017 Virgile
** Last update Sun Jan 22 10:57:40 2017 Virgile
*/

#include "my.h"

int	my_strcmp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str2[i] != '\0')
    {
      if (str[i] != str2[i])
	return (0);
      i++;
    }
  if (str[i] != str2[i])
    return (0);
  return (1);
}

char	*conc(char *str, char *str2)
{
  int	i;
  char	*conc;
  int	j;

  j = 0;
  i = 0;
  conc = NULL;
  if ((conc = malloc(my_strlen(str) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
      while (str != NULL && str[i])
	{
	  conc[i] = str[i];
	  i++;
	}
      while (str2 != NULL && str2[j])
	{
	  conc[i] = str2[j];
	  j++;
	  i++;
	}
  conc[i] = '\0';
  return (conc);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr_error(char *str)
{
  write(2, str, my_strlen(str));
  return (84);
}

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
