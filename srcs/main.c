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
	if (ac == 4 || ac == 5)
	{
		printf("Ok\n");
		return (0);
	}
	printf("Usage: $> ./philo \"number of philosofers\" \"time to die\" ");
	printf("\"time to eat\" \"time to sleep\" ");
	printf("\"number of times each philosofer must eat (optional)\"\n");
	return (1);
}
