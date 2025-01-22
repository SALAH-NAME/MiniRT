/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:34:45 by souahidi          #+#    #+#             */
/*   Updated: 2024/09/02 00:34:47 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_length(void *list)
{
	int		length;
	t_list	*current;

	length = 0;
	current = list;
	while (current)
	{
		current = current->next;
		length++;
	}
	return (length);
}
