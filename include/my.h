/*
** my.h for my in /home/pion_b/PSU_2016_minishell1
**
** Made by Virgile
** Login   <pion_b@epitech.net>
**
** Started on  Mon Jan 16 13:45:46 2017 Virgile
** Last update Sun Jan 22 16:55:36 2017 Virgile
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "get_next_line.h"

typedef struct		s_shell
{
  int			i;
  int			ret;
  int			error;
  char			*input;
  char			**env;
  char			**av;
  char			**path;
  pid_t			pid;
  char			cwd[1000];
  char			*signals[64];
  int			*size;
}			t_shell;


void			init_shell(t_shell *sh);
void			exec_child(t_shell *sh);
void			printab(char **tab);
int			my_buildin(t_shell *sh);
char			*my_epurstr(char *str);
void			my_putnbr(int nb);
void			my_putchar(char c);
void			my_sighandler(int signal, t_shell *sh);
int			my_getnbr(char *str);
char			**my_unsetenv(char **env, char *var);
char			**my_setenv(char **env, char *var, char *value);
void			delete_tab(char **tab);
char			*conc(char *str, char *str2);
int			my_env_cmp(char *env_var, char *var);
int			my_strcmp(char *str, char *str2);
char			*my_getenv(char **env, char *var);
char**			my_str_to_wordtab(char *str, char separation);
void			my_putchar(char c);
void			my_putstr(char *str);
int			my_putstr_error(char *str);
int			my_strlen(char *str);
int			main(int ac, char **av, char **env);
char			*my_strcpy(char *str);
char			**my_add_to_tab(char **tab, char *new);
#endif /*MY_H_*/
