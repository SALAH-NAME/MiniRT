/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:59:09 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/04 22:03:46 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_stack(const char *str, char *buf, char **ptrs)
{
	int	word_count;
	int	pos;

	word_count = 0;
	pos = 0;
	if (!str)
		return ;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str)
		{
			ptrs[word_count] = &buf[pos];
			while (!ft_isspace(*str) && pos < 4095)
				buf[pos++] = *str++;
			buf[pos++] = '\0';
			word_count++;
			if (word_count >= 200 || pos >= 4095)
				return ;
		}
	}
	ptrs[word_count] = NULL;
	return ;
}
