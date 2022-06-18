/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:12:22 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/18 23:04:31 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_shadow_ray(t_elements *elem, t_cogo sh_r, t_cogo o, int index)
{
	int	i;
	int j;

	i = -1;
	j = 1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		if (i != index && !check_sh_r_sp(elem, sh_r, (size_t)i, o))
			j = 0;
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		if (i != index && !check_sh_r_pl(elem, sh_r, (size_t)i, o))
			j = 0;
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (i != index && !check_sh_r_cy(elem, sh_r, (size_t)i, o))
			j = 0;
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (i != index && !check_sh_r_cy_disk(elem, sh_r, (size_t)i, o))
			j = 0;
	return (j);
}
