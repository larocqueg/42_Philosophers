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

static void	ft_complete_lst(t_philo *philos, char **av, int i)
{
	if (i == 5)
		philos->eat_quant = ft_atol(av[i--]);
	philos->sleep_time = ft_atol(av[i--]);
	philos->eat_time = ft_atol(av[i--]);
	philos->die_time = ft_atol(av[i--]);
	philos->philos_count = ft_atol(av[i]);
}

int	main(int ac, char **av)
{
	int	i;
	int	valid;
	t_philo	philos;

	if (ac == 4 || ac == 5)
	{
		i = 1;
		valid = 1;
		while (av[i])
		{
			if (!ft_is_valid(av[i++]))
				return (printf("%s", INVALID_ARG), 1);
		}
		ft_complete_lst(&philos, av, i);
		printf("eat quant = %ld\n", philos.eat_quant);
		printf("eat time = %ld\n", philos.eat_time);
		printf("sleep time = %ld\n", philos.sleep_time);
		printf("die time = %ld\n", philos.die_time);
		printf("philos count = %ld\n", philos.philos_count);
		return (0);
	}
	printf("Usage: $> ./philo \"number of philosofers\" \"time to die\" ");
	printf("\"time to eat\" \"time to sleep\" ");
	printf("\"number of times each philosofer must eat (optional)\"\n");
	return (1);
}
