/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:20:41 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/01 15:30:14 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef enum e_op
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_op;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals; // meals counter
	long		last_meal; // last time the philo eat
	bool		full; // if av[5] is given and it reaches the number full = true
	t_fork		*left_fork; // pointer to the left fork
	t_fork		*right_fork; // pointer to the right fork
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	long		philos_count; // number of philos on the table
	long		die_time; // the time a philo dies if it doesn't eat
	long		eat_time; // the time a philo has to wait to eat
	long		sleep_time; // the time a philo has to sleep
	long		eat_quant; // if the user gives the av[5]
	bool		startd;
	bool		ended;
	t_fork		*forks;
	t_philo		*philos;
}	t_table;

//parsing.c
void	parsing(char **av, int ac);

//exit.c
void	exit_code(int code, char *message);

//init.c
void	init_table(t_table *table, char **av, int ac);

//safes.c
void	*safe_malloc(size_t bytes);

//free.c
void	clean_table(t_table *table);

//utils.c
long	ft_atol(char *str);
int		is_digit(char c);
int		is_space(char c);

// MESSAGES
# define ARG_1        "Usage: $> ./philo \"number of philos\" "
# define ARG_2        "\"time to die\" \"time to eat\" \"time to sleep\" "
# define ARG_3        "\"number of times each philos must eat (optional)\"\n"
# define LIMITS       "Only positive numbers within int limits are allowed!\n"
# define INVALID_ARG  "Only numeric arguments are allowed!\n"
# define MALLOC_ERROR "No avaiable memory on your system! Malloc error!\n"
# define ENUM_ERROR   "Wrong operation code given to mutex!\n"

#endif
