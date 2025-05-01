/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:05:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/01 13:06:34 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_limits(t_philo *phi)
{
	if ((phi->eat_quant > INT_MAX)
		|| ((phi->eat_quant == 0 || phi->eat_quant <= 0) && (phi->six)))
		return (0);
	if (phi->sleep_time > INT_MAX || phi->sleep_time <= 0)
		return (0);
	if (phi->eat_time > INT_MAX || phi->eat_time <= 0)
		return (0);
	if (phi->die_time > INT_MAX || phi->die_time <= 0)
		return (0);
	if (phi->philos_count > INT_MAX || phi->philos_count <= 0)
		return (0);
	return (1);
}

int	check_len(char *str)
{
	int		i;
	int		j;
	char	sig;

	i = 0;
	sig = '\0';
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sig = str[i++];
	j = i;
	while (is_digit(str[i]))
		i++;
	if (sig == '-' && (i - j > 20))
		return (0);
	else if ((!sig || sig == '+') && (i - j) > 19)
		return (0);
	return (1);
}

int	ft_complete_lst(t_philo *philos, char **av, int i)
{
	int	j;

	j = i;
	while (j >= 1)
	{
		if (!check_len(av[j--]))
			return (0);
	}
	if (i == 5)
		philos->eat_quant = ft_atol(av[i--]);
	else
		philos->eat_quant = -1;
	philos->sleep_time = ft_atol(av[i--]);
	philos->eat_time = ft_atol(av[i--]);
	philos->die_time = ft_atol(av[i--]);
	philos->philos_count = ft_atol(av[i]);
	if (!check_limits(philos))
		return (0);
	return (1);
}

void	print_philos(t_philo *philos)
{
	printf("philos count = %ld\n", philos->philos_count);
	printf("die time = %ld\n", philos->die_time);
	printf("eat time = %ld\n", philos->eat_time);
	printf("sleep time = %ld\n", philos->sleep_time);
	if (philos->six == true)
		printf("eat quant = %ld\n", philos->eat_quant);
	else
		printf("eat quant not given\n");
}
