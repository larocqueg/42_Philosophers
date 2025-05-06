/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:19:18 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/01 15:20:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_args(t_table *table)
{
	printf("philos_count = %ld\n", table->philos_count);
	printf("die_time = %ld\n", table->die_time);
	printf("eat_time = %ld\n", table->eat_time);
	printf("sleep_time = %ld\n", table->sleep_time);
	printf("eat_quant = %ld\n", table->eat_quant);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		parsing(av, ac);
		init_table(&table, av, ac);
		print_args(&table);
		clean_table(&table);
		return (0);
	}
	printf(ARG_1 ARG_2 ARG_3);
	return (1);
}
