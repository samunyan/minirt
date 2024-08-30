/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:19:56 by samunyan          #+#    #+#             */
/*   Updated: 2023/06/02 12:01:10 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse(t_scene *scene, char *filepath)
{
	int	fd;
	int	ret;

	if (!check_file_name(filepath))
	{
		mrt_error(mrt_strerror, ERRNUM_FILE, NULL);
		return (false);
	}
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		mrt_error(strerror, errno, filepath);
		return (false);
	}
	if (!parse_file(scene, fd))
		ret = false;
	else
		ret = scene_is_valid(scene);
	close(fd);
	return (ret);
}

int	parse_file(t_scene *scene, int fd)
{
	char	*line;
	int		ret;
	int		line_nb;

	line_nb = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_nb++;
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		ret = parse_line(scene, line, line_nb);
		free(line);
		if (!ret)
			return (false);
	}
	return (true);
}

int	parse_line(t_scene *scene, char *line, int line_nb)
{
	char	**data;
	int		ret;

	data = ft_split_set(line, " \t");
	if (!data)
	{
		ft_err_msg(strerror, errno, "parse_line");
		return (false);
	}
	ret = parse_lookup(scene, data, line_nb);
	ft_free_arr((void **)data);
	return (ret);
}

static t_parse_dispatch	g_parse_dispatch[] = {
{"A", parse_ambient_light},
{"L", parse_diffuse_light},
{"C", parse_camera},
{"sp", parse_sphere},
{"pl", parse_plane},
{"cy", parse_cylinder},
{NULL, NULL}
};

int	parse_lookup(t_scene *scene, char **data, int line_nb)
{
	size_t	i;

	i = 0;
	while (g_parse_dispatch[i].id)
	{
		if (ft_strcmp(data[0], g_parse_dispatch[i].id) == 0)
			return (g_parse_dispatch[i].f(scene, data, line_nb));
		i++;
	}
	mrt_parse_error(ERRNUM_ID, line_nb, data[0]);
	return (false);
}
