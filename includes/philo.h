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
long	ft_atol(char *str);

//string_utils.c
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		is_digit(char c);
int		is_space(char c);
int		ft_is_valid(char *str);


# define INVALID_ARG "Only numeric arguments are allowed!\n"
# define ARG_1       "Usage: $> ./philo \"number of philosofers\" "
# define ARG_2       "\"time to die\" \"time to eat\" \"time to sleep\" "
# define ARG_3       "\"number of times each philosofer must eat (optional)\"\n"
# define LIMITS      "Only positive numbers within int limits are allowed!"

#endif
