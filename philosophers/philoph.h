#ifndef PHILOPH_H
# define PHILOPH_H

# include <stdio.h> //printf
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h> // time
typedef struct s_couisine	t_couisine;

typedef struct s_phl
{
	t_couisine		*table;
	int				ind;
	int				et;
	size_t			le;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		patok;
	struct s_phl	*next;
}	t_phl;

typedef struct s_couisine
{
	int				nu_ph;
	int				ttd;
	int				tte;
	int				tts;
	int				nu_te;
	int				if_ded;
	int				ded_t;
	int				i;
	size_t			s_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*post;
	t_phl			*phs;
	pthread_t		smert;
}	t_couisine;

size_t		ph_time(t_couisine *table, int i);
void		upgrade_usleep(double msec);
long long	ph_atoi(char *str);
int			ph_check_argv(char **argv);
int			ph_parser(int argc, char **argv, t_couisine *table);

int			ph_err_ret(char *str, t_couisine *table);
int			ph_creat(t_couisine *table, int k);
int			ph_fork_init(t_couisine *table);
void		ph_post(char *str, t_phl *philo);
void		*ph_pasta(void *phil);

#endif