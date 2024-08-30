/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2023/05/31 12:20:28 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "minirt.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		pxlsize;
	int		sline;
	int		endian;
	int		color;
}	t_image;

typedef struct s_window
{
	void			*win;
	void			*ptr;
	struct s_image	*img;
}	t_window;

int		init_image(t_scene *scene);
void	clear_window(t_window *win);

#endif
