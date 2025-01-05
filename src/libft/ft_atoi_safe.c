/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:07:01 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/04 18:11:50 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_safe(const char *str, int *out)
{
	int		sign;
	long	output;

	sign = 1;
	output = 0;
	if (!str)
		return (out = 0, 0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (output > (LONG_MAX - (*str - '0')) / 10)
			return (0);
		output = (output * 10) + (*str - '0');
		str++;
	}
	*out = output * sign;
	return (1);
}
