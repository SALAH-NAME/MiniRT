/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:35:13 by souahidi          #+#    #+#             */
/*   Updated: 2024/09/02 00:35:14 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

void	*list_at(void *list, int index)
{
	int		position;
	t_list	*current;

	position = 0;
	current = list;
	while (current && position < index)
	{
		current = current->next;
		position++;
	}
	return (current);
}

void	*list_tail(void *list)
{
	t_list	*current;

	current = list;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}
