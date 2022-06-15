/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring_mandatory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:33:32 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 09:59:06 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	fill_color_buffer(t_mlx_ptr *gfx, t_rgb color, int x, int y)
{
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i0] = color.b;
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i1] = color.g;
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i2] = color.r;
}

void	call_display_function(t_elements *elem, t_mlx_ptr *gfx)
{
	fill_position_matrix(elem);
	elem->a->single = 0;
	display(elem, gfx);
}
