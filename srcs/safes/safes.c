/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:26:36 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/05 15:29:23 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*dest;

	dest = malloc(bytes);
	if (dest == NULL)
		exit_code(1, MALLOC_ERROR);
	return (dest);
}

void	safe_mutex(t_mtx *mutex, t_op op)
{
	if (op == LOCK)
		pthrear_mutex_lock();
	else if (op == UNLOCK)
		pthread_mutex_unlock();
	else if (op == INIT)
		pthread_mutex_init();
	else if (op == DESTROY)
		pthread_mutex_destroy();
	else
		exit_code(1, ENUM_ERROR);
}
