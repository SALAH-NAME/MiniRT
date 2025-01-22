/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:35:06 by souahidi          #+#    #+#             */
/*   Updated: 2024/09/02 00:35:07 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

void	*list_map(void *list, void *(*f)(void *, int))
{
	int		index;
	t_list	*new;
	t_list	**current;
	t_list	*old;

	if (!list || !f)
		return (NULL);
	index = 0;
	new = NULL;
	old = list;
	current = &new;
	while (old)
	{
		*current = f(old, index);
		current = &(*current)->next;
		old = old->next;
		index++;
	}
	return (new);
}
