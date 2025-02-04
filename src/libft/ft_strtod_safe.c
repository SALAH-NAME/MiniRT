/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:37:37 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/03 15:52:10 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	exponent_strtod(const char *s, double n, double exponent)
{
	if (*s++ == '.')
	{
		while (ft_isdigit(*s))
		{
			n = (n * 10.0) + (*s++ - '0');
			exponent *= 10.0;
		}
	}
	return (n /= exponent);
}

int	ft_strtod_safe(const char *s, double *out)
{
	double	n;
	int		negative;
	double	exponent;

	n = 0.0;
	negative = 1.0;
	exponent = 1.0;
	if (s == NULL || out == NULL)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		negative = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		if (n > (LONG_MAX - (*s - '0')) / 10)
			return (0);
		n = (n * 10.0) + (*s++ - '0');
	}
	n = exponent_strtod(s, n, exponent);
	*out = n * negative;
	return (1);
}
