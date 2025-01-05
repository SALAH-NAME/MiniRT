/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:26:51 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/01 17:26:51 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numvalid(const char *s)
{
	const char	*tmp;

	if (!s || !*s)
		return (0);
	tmp = s;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	while (*tmp && ft_isdigit(*tmp))
		tmp++;
	return (!*tmp);
}
