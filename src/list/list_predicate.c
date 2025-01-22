/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_predicate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:35:00 by souahidi          #+#    #+#             */
/*   Updated: 2024/09/02 00:35:01 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

int	list_any(void *list, int (*p)(void *, int))
{
	int		index;
	t_list	*current;

	if (!list || !p)
		return (0);
	index = 0;
	current = list;
	while (current)
	{
		if (p(current, index))
			return (1);
		current = current->next;
		index++;
	}
	return (0);
}

int	list_every(void *list, int (*p)(void *, int))
{
	int		index;
	t_list	*current;

	if (!list || !p)
		return (0);
	index = 0;
	current = list;
	while (current)
	{
		if (!p(current, index))
			return (0);
		current = current->next;
		index++;
	}
	return (1);
}
