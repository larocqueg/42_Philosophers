/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:30:27 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/01 16:35:01 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_table(t_table *table, char **av, int ac)
{
	int	i;

	i = ac - 1;
	if (ac == 6)
		table->eat_quant = ft_atol(av[i--]);
	else
		table->eat_quant = -1;
	table->sleep_time = ft_atol(av[i--]);
	table->eat_time = ft_atol(av[i--]);
	table->die_time = ft_atol(av[i--]);
	table->philos_count = ft_atol(av[i--]);
	table->ended = false;
	table->philos = safe_malloc(table->philos_count);
}
