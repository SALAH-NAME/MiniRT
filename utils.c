/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:56:17 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/31 13:56:17 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "miniRT.h"

int	valid(char **info, int count)
{
	int	i;

	i = 0;
	if (!info)
		return (0);
	while (i < count)
		if (!info[i++])
			return (0);
	return (1);
}

void	free_all(t_file *file)
{
	char	**tmp;

	if (file)
	{
		tmp = file->lines;
		while (tmp && *tmp)
			free(*(tmp++));
		free(file->lines);
		free(file->content);
		free(file);
	}
}
