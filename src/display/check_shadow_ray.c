/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:12:22 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 16:33:51 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_shadow_ray(t_elements *elem, t_cogo sh_ray, t_cogo o)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		if (!check_sh_ray_sp(elem, sh_ray, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		if (!check_sh_ray_pl(elem, sh_ray, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (!check_sh_ray_cy(elem, sh_ray, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (!check_sh_ray_cy_disk(elem, sh_ray, (size_t)i, o))
			return (0);
	return (1);
}
