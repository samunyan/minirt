/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <gscarama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2023/05/31 12:20:09 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "minirt.h"

# ifdef LINUX
#  define KEY_ESCAPE			65307
#  define XDESTROY_NOTIFY		33
# else
#  define KEY_ESCAPE			53
#  define XDESTROY_NOTIFY		17
# endif

int	key_hook(int key, t_scene *scene);
int	hook_exit(t_scene *scene);

#endif
