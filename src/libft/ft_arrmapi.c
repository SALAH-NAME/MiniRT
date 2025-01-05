/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:09:09 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/03 18:09:45 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrmapi(char **arr, void (*f)(void *))
{
	int	i;

	i = 0;
	if (arr == NULL || f == NULL || *arr == NULL)
		return ;
	while (arr[i])
	{
		if (arr[i] != NULL)
		{
			f(arr[i]);
			arr[i++] = NULL;
		}
	}
	f(arr);
	arr = NULL;
}
