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

#include "../includes/philo.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

int	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_digit(str[i]))
		i++;
	if (str[i] && !is_digit(str[i]))
		return (0);
	return (1);
}

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
	if (ft_strlen(str + i) > 20 && sig == -1)
		return (-2147483648);
	if (ft_strlen(str + i) > 19 && sig == 1)
		return (2147483647);
	while (is_digit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
