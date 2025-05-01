/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:49:07 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/25 14:53:33 by gde-la-r         ###   ########.fr       */
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

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meal_counter; // counts the number of meals
	long		philos_count; // number of philos on the table
	long		die_time; // the time a philo dies if it doesn't eat
	long		eat_time; // the time a philo has to wait to eat
	long		sleep_time; // the time a philo has to sleep
	long		eat_quant; // Max of 5
	bool		six; // if ac == 6 six == true; else six == false
	bool		full; // if six == true && eat_quant == 0; full == true
	t_fork		*left_fork; // pointer to the left fork
	t_fork		*right_fork; // pointer to the right fork
	pthread_t	thread_id; // every philo is a thread and here is the thread id
}	t_philo;

typedef struct s_table
{
	bool		start; // true when the treads start
	bool		end; // true when the threads end
	t_fork		*forks;
	t_philo		*philos;
}	t_table;

//utils.c
long	ft_atol(char *str);

//string_utils.c
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		is_digit(char c);
int		is_space(char c);
int		ft_is_valid(char *str);

//parsing.c
int		check_limits(t_philo *phi);
int		check_len(char *str);
int		ft_complete_lst(t_philo *philos, char **av, int i);
void	print_philos(t_philo *philos);

# define INVALID_ARG "Only numeric arguments are allowed!\n"
# define ARG_1       "Usage: $> ./philo \"number of philosofers\" "
# define ARG_2       "\"time to die\" \"time to eat\" \"time to sleep\" "
# define ARG_3       "\"number of times each philosofer must eat (optional)\"\n"
# define LIMITS      "Only positive numbers within int limits are allowed!"

#endif
