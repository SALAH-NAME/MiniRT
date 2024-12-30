/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:42 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/30 12:15:32 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_all(t_file *file)
{
	free(file->content);
	free(file);
}

int	main(int ac, char **av)
{
	t_file	*file;

	if (ac != 2)
	{
		printf("Usage: %s <file>\n", av[0]);
		return (1);
	}
	file = file_parse(av[1]);
	free_all(file);
	return (0);
}
