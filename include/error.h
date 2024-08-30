/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:34:51 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/01 14:52:15 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minirt.h"

// File input errors
# define ERRMSG_ARGS	"Wrong number of arguments. Usage: ./miniRT <*.rt>"
# define ERRNUM_ARGS	1
# define ERRMSG_FILE	"Wrong file extension. Usage: ./miniRT <*.rt>"
# define ERRNUM_FILE	2
# define ERRMSG_SCENE	"Not a valid scene file"
# define ERRNUM_SCENE	3
// File parsing errors
# define ERRMSG_ID		"Not a valid identifier"
# define ERRNUM_ID		4
# define ERRMSG_RANGE	"Range error"
# define ERRNUM_RANGE	5
# define ERRMSG_UNIT	"Orientation vector is zero vector"
# define ERRNUM_UNIT	6
# define ERRMSG_SPECS	"Wrong number of specifications"
# define ERRNUM_SPECS	7
# define ERRMSG_FORMAT	"Wrong format"
# define ERRNUM_FORMAT	8
// Total amount of error messages
# define NB_ERRORS		8

# define ERR_BUFSIZE	4096

int		mrt_error(char *(*f)(int), int errnum, const char *msg);
typedef struct s_error_dispatch {
	int		errnum;
	char	*errmsg;
}	t_error_dispatch;
char	*mrt_strerror(int errnum);
int		mrt_parse_error(int errnum, int line_nb, const char *msg);

#endif
