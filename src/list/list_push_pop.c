/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:03:47 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 16:03:48 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

void	list_push(void **list, void *node)
{
	t_list	*tail;

	if (!list || !node)
		return ;
	if (!*list)
		*list = node;
	else
	{
		tail = list_tail(*list);
		tail->next = node;
	}
}

void	*list_pop(void **list)
{
	t_list	*tail;
	t_list	*current;

	if (!list || !*list)
		return (NULL);
	current = *list;
	if (!current->next)
	{
		*list = NULL;
		return (current);
	}
	while (current->next->next)
		current = current->next;
	tail = current->next;
	current->next = NULL;
	return (tail);
}
