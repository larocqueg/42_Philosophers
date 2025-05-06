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

static void	mutex_error(int status, t_op op)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (op == LOCK || op == UNLOCK))
		exit_code(1, MUTEX);
	else if (status == EINVAL && op == INIT)
		exit_code(1, ATTR);
	else if (status == EDEADLK)
	{
		printf(DEADLOCK);
		exit_code(1, DEADLOCK2);
	}
	else if (status == ENOMEM)
		exit_code(1, MEMORY);
	else if (status == EBUSY)
		exit_code(1, MUTEX_LOCKED);
}

void	safe_mutex(t_mtx *mutex, t_op op)
{
	if (op == LOCK)
		mutex_error(pthread_mutex_lock(mutex), op);
	else if (op == UNLOCK)
		mutex_error(pthread_mutex_unlock(mutex), op);
	else if (op == INIT)
		mutex_error(pthread_mutex_init(mutex, NULL), op);
	else if (op == DESTROY)
		mutex_error(pthread_mutex_destroy(mutex), op);
	else
		exit_code(1, ENUM_ERROR);
}

static void	thread_erro(int status, t_op op)
{
	if (status == 0)
		return ;
	else if ()
}

void	safe_thread(pthread_t *thread, void*(*f)(void *))
{
}
