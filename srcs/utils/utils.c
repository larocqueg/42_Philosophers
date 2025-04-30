/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:59:06 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/25 15:05:28 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	ft_atol(char *str)
{
	int		i;
	int		sig;
	long	n;

	i = 0;
	n = 0;
	sig = 1;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	if (ft_strcmp(str, "2147483647") == 0)
		return (2147483647);
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sig);
}
