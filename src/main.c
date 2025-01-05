/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:42 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 21:07:15 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"



int	init(t_data *data, char *av)
{
	if (parse_config_init(data))
		return (1);
	if (load(data, av))
		return (free_all(data), 1);
	return (0);
}

int	main(int ac, char **av)
{

	t_data	*data;

	if (ac != 2)
	{
		printf("Usage: %s <file>\n", av[0]);
		return (1);
	}
	if (valid_file_name(av[1]))
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (data)
	{
		if (init(data, av[1]))
			return (free_all(data), 1);
	}
	free_all(data);
	return (0);
}
