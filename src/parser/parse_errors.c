/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:14:13 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/01 12:34:47 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	print_hint_error(char *hint)
{
	ft_putstr_fd("Hint: ", 2);
	ft_putstr_fd(hint, 2);
	ft_putstr_fd("----------------------------------------", 2);
	ft_putendl_fd("----------------------------------------", 2);
}

static void	print_error(t_error *er)
{
	char	*line_num;

	line_num = ft_itoa(er->line_number);
	ft_putstr_fd("----------------------------------------", 2);
	ft_putendl_fd("----------------------------------------", 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("----------------------------------------", 2);
	ft_putendl_fd("----------------------------------------", 2);
	ft_putstr_fd("In file '", 2);
	ft_putstr_fd(er->file_name, 2);
	ft_putstr_fd("' at line ", 2);
	ft_putstr_fd(line_num, 2);
	ft_putendl_fd(":", 2);
	ft_putstr_fd("----------------------------------------", 2);
	ft_putendl_fd("----------------------------------------", 2);
	ft_putstr_fd("Description: ", 2);
	ft_putstr_fd(er->description, 2);
	ft_putstr_fd(" '", 2);
	ft_putstr_fd(er->problem, 2);
	ft_putendl_fd("'", 2);
	ft_putstr_fd("----------------------------------------", 2);
	ft_putendl_fd("----------------------------------------", 2);
	if (*er->hint)
		print_hint_error(er->hint);
	free(line_num);
}

void	set_error(t_data *data, char *desc, char *pr, char *hint)
{
	t_error	error;

	if (data->file->error == 0)
		return ;
	data->file->error = 0;
	error.file_name = data->file->file_name;
	error.line_number = data->file->line_index;
	error.description = desc;
	error.problem = pr;
	error.hint = "\0";
	if (hint)
		error.hint = hint;
	print_error(&error);
}

void	check_errors(t_data *data)
{
	if (data->scene.count.a_c == 0)
		set_error(data, ERR_MS_A, NULL, NULL);
	if (data->scene.count.c_c == 0)
		set_error(data, ERR_MS_C, NULL, NULL);
	if (data->scene.count.l_c == 0)
		set_error(data, ERR_MS_L, NULL, NULL);
	if (data->scene.count.pl_c == 0)
		set_error(data, ERR_MS_PL, NULL, NULL);
	if (data->scene.count.sp_c == 0)
		set_error(data, ERR_MS_SP, NULL, NULL);
	if (data->scene.count.cy_c == 0)
		set_error(data, ERR_MS_CY, NULL, NULL);
	if (data->scene.count.l_c > data->config->elements[LIGHT].max_count)
		set_error(data, ERR_INV_ARG_NUM, "L", NULL);
	else if (data->scene.count.c_c > data->config->elements[CAMERA].max_count)
		set_error(data, ERR_INV_ARG_NUM, "C", NULL);
	else if (data->scene.count.a_c > data->config->elements[AMBIENT].max_count)
		set_error(data, ERR_INV_ARG_NUM, "A", NULL);
}
