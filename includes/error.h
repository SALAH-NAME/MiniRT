/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:16:03 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 19:57:19 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "stdlib.h"

typedef struct s_error
{
	int		code;
	char	*description;
	char	*file_name;
	size_t	line_number;
	char	*problem;
	char	*hint;
}			t_error;

// error codes
# define ERR_MS_A "Missing 'A' for ambient light"
# define ERR_MS_C "Missing 'C' for camera"
# define ERR_MS_L "Missing 'L' for light source"
# define ERR_MS_PL "Missing 'pl' for plane"
# define ERR_MS_SP "Missing 'sp' for sphere"
# define ERR_MS_CY "Missing 'cy' for cylinder"
# define ERR_MS_SQ "Missing 'sq' for square"
# define ERR_MS_CN "Missing 'cn' for cone"

# define ERR_INV_VAL_POS "Invalid value: expected a number but found:"
# define ERR_MS_VAL_PARAM "Incorrect number of parameters for object type:"
# define ERR_INV_COLOR_FMT "Invalid color format: expected 'R,G,B' but found:"
# define ERR_INV_ARG_NUM "Incorrect number of arguments for object type:"
# define ERR_UNREC_OBJ_TYPE "Unrecognized object type in the scene."
# define ERR_INV_COORD "Invalid coordinate format: expected 'x,y,z' but found:"
# define ERR_INV_OBJ_SIZE "Invalid object size: expected a positive number."
# define ERR_OUT_OF_BOUNDS "Out of bounds value for a specific parameter."
# define ERR_MS_OBJ_ATTR "Missing object attribute in the scene definition."
# define ERR_UNEXP_EOF "Unexpected end of file during parsing."
# define ERR_INV_FLOAT_FMT "Invalid floating-point number format."
# define ERR_UNEXP_TOKEN "Unexpected token found in the input file."
# define ERR_MS_COMMA_SEP "Missing comma or separator between values."
# define ERR_VAL_TOO_LARGE "Value too large or too small for parameter."
# define ERR_INV_LIGHT_POS "Invalid light source position format."
# define ERR_INV_RADIUS "Invalid radius for sphere or cylinder."
# define ERR_INV_NORM_VEC "Invalid normal vector for plane or object."
# define ERR_SYNTAX "Syntax error in scene file."

// ratio errors
# define ERR_MS_RATIO "Missing ratio value."
# define ERR_RATIO_V "Invalid ratio value."
# define ERR_RATIO_R "Ratio value must be between 0 and 1."
// color errors
# define ERR_MS_COLOR "Invalid color format: expected 'R,G,B' but found:"
# define ERR_COLOR_V "Invalid color value."
# define ERR_COLOR_R "Color value must be between 0 and 255."
// coordinate errors
# define ERR_MS_COORD "Invalid coordinate format: expected 'x,y,z' but found:"
# define ERR_COORD_V "Invalid coordinate value."
# define ERR_COORD_R "Coordinate value is too large."
// vector errors
# define ERR_MS_VECTOR "Invalid vector format: expected 'x,y,z' but found:"
# define ERR_VECTOR_V "Invalid vector value."
# define ERR_VECTOR_R "Vector values must be between -1 and 1."
// degree errors
# define ERR_MS_DEGREE "Invalid degree format: expected a number but found:"
# define ERR_DEGREE_V "Invalid degree value."
# define ERR_DEGREE_R "Degree value must be between 0 and 180."

void		set_error(t_data *data, char *desc, char *pr, char *hint);
void		check_errors(t_data *data);
#endif
