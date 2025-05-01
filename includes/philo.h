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

typedef strcut s_fork
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
	t_philos	*philos;
}	t_table;

#endif
