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

typedef struct s_philo
{
	int		id;
	long	philos_count;
	long	die_time;
	long	eat_time;
	long	sleep_time;
	long	eat_quant;
}	t_philo;

//utils.c
int		is_digit(char c);
int		is_space(char c);
int		ft_is_valid(char *str);
int		ft_strlen(char *str);
long	ft_atol(char *str);

# define INVALID_ARG "Only numeric arguments are allowed!\n"

#endif
