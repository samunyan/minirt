/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:19:48 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/07 15:01:14 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

typedef struct s_parse_dispatch
{
	char	*id;
	int		(*f)(t_scene *scene, char **data, int line_nb);
}	t_parse_dispatch;

size_t	arrlen(char **arr);
int		parse(t_scene *scene, char *filepath);
int		parse_file(t_scene *scene, int fd);
int		parse_line(t_scene *scene, char *line, int line_nb);
int		parse_lookup(t_scene *scene, char **data, int line_nb);
int		parse_ambient_light(t_scene *scene, char **data, int line_nb);
int		parse_diffuse_light(t_scene *scene, char **data, int line_nb);
int		parse_camera(t_scene *scene, char **data, int line_nb);
int		parse_sphere(t_scene *scene, char **data, int line_nb);
int		parse_plane(t_scene *scene, char **data, int line_nb);
int		parse_cylinder(t_scene *scene, char **data, int line_nb);
int		parse_material_default_attr(char *src, t_mtl *mtl, int line_nb);

int		str_to_3_doubles(char *src, t_vec3 *dst, int ints_in_str);
int		str_to_1_double(char *src, double *dst, int int_in_str);

int		double_is_in_range(double d, double min, double max);
int		vec3_is_in_range(t_vec3 *v, double min, double max);
int		str_contains_double(const char *s);
int		str_contains_int(const char *s);
int		check_file_name(const char *filepath);

int		scene_is_valid(t_scene *scene);

#endif
