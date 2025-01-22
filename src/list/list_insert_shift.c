/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:34:35 by souahidi          #+#    #+#             */
/*   Updated: 2024/09/02 00:34:40 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

void	list_insert(void **list, void *node)
{
	t_list	*new;

	if (!list || !node)
		return ;
	new = node;
	new->next = *list;
	*list = new;
}

void	*list_shift(void **list)
{
	t_list	*head;

	if (!list || !*list)
		return (NULL);
	head = *list;
	*list = head->next;
	return (head);
}
