/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:03:59 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 16:04:00 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>
#include <stdlib.h>

void	list_free(void **list, void (*f)())
{
	t_list	*next;
	t_list	*current;

	if (!list)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		if (f)
			f(current);
		free(current);
		current = next;
	}
	*list = NULL;
}
