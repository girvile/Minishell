/*
** signal.c for signal in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Thu Jan 19 14:15:33 2017 Virgile
** Last update Sun Jan 22 19:15:57 2017 Virgile
*/

#include "my.h"

int	my_epurlen(char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  j++;
	  while (str[i] == ' ')
	    i++;
	}
      else
	{
	  i++;
	  j++;
	}
    }
  return (j);
}

char	*my_epurspace(char *str, char *new_str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] == ' ')
    i++;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  new_str[j] = str[i];
	  while (str[i] == ' ')
	    i++;
	  if (str[i] == '\0')
	    new_str[j] = str[i];
	  j++;
	}
      else
	  new_str[j++] = str[i++];
    }
  new_str[j] = '\0';
  return (new_str);
}

char	*my_epurstr(char *str)
{
  int	i;
  char	*new_str;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
    i++;
    }
  if ((new_str = malloc(sizeof(char) * (my_epurlen(str) + 1))) == NULL)
    exit (1);
  return (my_epurspace(str, new_str));
}

void	my_putnbr(int nb)
{
  int	n;

  if (nb < 0)
    nb = -nb;
  if (nb < 10)
    my_putchar(nb + '0');
  if (nb > 9)
    {
      n = nb % 10;
      my_putnbr(nb / 10);
      my_putchar(n + '0');
    }
}

void	my_sighandler(int signal, t_shell *sh)
{
  int	s;

  s = signal;
  signal = WTERMSIG(signal);
  if (signal > 0 && signal < 64)
    my_putstr_error(sh->signals[signal]);
  if (WEXITSTATUS(s) != 0)
    sh->error = WEXITSTATUS(s);
}
