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

int	main(int ac, char **av)
{
	int		i;
	t_philo	philos;

	if (ac == 6 || ac == 5)
	{
		i = 0;
		philos.ac = ac;
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
