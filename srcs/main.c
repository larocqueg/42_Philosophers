/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:53:53 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/25 14:57:43 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_limits(t_philo *philos)
{
	if (philos->eat_quant > INT_MAX || philos->eat_quant <= 0)
		return (0);
	if (philos->sleep_time > INT_MAX || philos->sleep_time <= 0)
		return (0);
	if (philos->eat_time > INT_MAX || philos->eat_time <= 0)
		return (0);
	if (philos->die_time > INT_MAX || philos->die_time <= 0)
		return (0);
	if (philos->philos_count > INT_MAX || philos->philos_count <= 0)
		return (0);
	return (1);
}

static int	check_len(char *str)
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

static int	ft_complete_lst(t_philo *philos, char **av, int i)
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

static void	print_philos(t_philo *philos)
{
	printf("philos count = %ld\n", philos->philos_count);
	printf("die time = %ld\n", philos->die_time);
	printf("eat time = %ld\n", philos->eat_time);
	printf("sleep time = %ld\n", philos->sleep_time);
	printf("eat quant = %ld\n", philos->eat_quant);
}

int	main(int ac, char **av)
{
	int		i;
	t_philo	philos;

	if (ac == 5 || ac == 6)
	{
		i = 0;
		while (++i < ac)
		{
			if (!ft_is_valid(av[i]))
				return (printf("%s", INVALID_ARG), 1);
		}
		if (!ft_complete_lst(&philos, av, ac - 1))
			return (printf("%s\n", LIMITS), 1);
		print_philos(&philos);
		return (0);
	}
	printf("%s%s%s", ARG_1, ARG_2, ARG_3);
	return (1);
}
