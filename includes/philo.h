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

typedef struct	s_philo
{
	int		id;
	long	number_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	eat_times;
}	t_philo;

//utils.c
int		is_digit(char c);
int		is_space(char c);
int		ft_is_valid(char *str);
long	ft_atol(char *str);

#endif
