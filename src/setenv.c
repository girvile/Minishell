/*
** setenv.c for setenv in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan 16 17:50:29 2017 Virgile
** Last update Sun Jan 22 11:28:36 2017 Virgile
*/

#include <stdio.h>
#include "my.h"

int		my_env_cmp(char *env_var, char *var)
{
  int		i;
  int		ok;

  ok = 1;
  i = 0;
  while (env_var[i] != '\0' && env_var[i] != '=' && var[i] != '\0')
    {
      if (env_var[i] != var[i])
	ok = 0;
      i++;
    }
  return (ok);
}

int		my_get_ac_tab(char **env)
{
  int		i;

  i = 0;
  if (env == NULL)
    return (0);
  while (env[i] != NULL)
      i++;
  return (i);
}

char		**my_unsetenv(char **env, char *var)
{
  int		i;
  char		**new_env;
  int		j;

  i = -1;
  if (((new_env = NULL) == NULL) && (env == NULL || var == NULL))
    return (env);
  while (env[++i])
    {
      if (my_env_cmp(env[i], var))
	{
	  if ((new_env = malloc(sizeof(char *) *			\
				(my_get_ac_tab(env) + 1))) == NULL)
	    return (NULL);
	  i = -1;
	  j = 0;
	  while (env[++i] != NULL)
	    if (my_env_cmp(env[i], var) == 0)
	      new_env[j++] = my_strcpy(env[i]);
	  new_env[j] = NULL;
	  return (new_env);
	}
    }
  return (env);
}

char		**my_setenv(char **env, char *var, char *value)
{
  int		i;

  i = 0;
  if (env == NULL)
    return (NULL);
  if (my_getenv(env, var) == NULL)
    return (my_add_to_tab(env, conc(conc(var, "="), value)));
  while (env[i] != NULL)
    {
      if (my_env_cmp(env[i], var) == 1)
	{
	  free(env[i]);
	  env[i] = conc(conc(var, "="), value);
	}
      i++;
    }
  return (env);
}

char		*my_getenv(char **env, char *var)
{
  int		i;
  int		j;
  char		*value;

  j = 0;
  value = NULL;
  if (((i = 0) == 0) && (env == NULL || env[i] == NULL))
    return (NULL);
  while (env[i] != NULL)
    {
      if (my_env_cmp(env[i], var) == 1)
	{
	  if ((value = malloc(sizeof(char) * ((my_strlen(env[i]) + 1)	\
					      - (my_strlen(var))))) == NULL)
	    return (NULL);
	  while (env[i][my_strlen(var) + j + 1] != '\0')
	    {
	      value[j] = env[i][my_strlen(var) + 1 + j];
	      j++;
	    }
	  value[j] = '\0';
	}
      i++;
    }
  return (value);
}
