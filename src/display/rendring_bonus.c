/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:36:46 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/13 11:31:21 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	fill_color_buffer(t_mlx_ptr *gfx, t_rgb color, int x, int y)
{
	t_rgb	buf_color;

	buf_color.b = gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i0];
	buf_color.g = gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i1];
	buf_color.r = gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i2];
	color = add_rgb(buf_color, color);
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i0] = color.b;
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i1] = color.g;
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i2] = color.r;
}

void    call_display_function(t_elements *elem, t_mlx_ptr *gfx)
{
    int		i;
	t_light *l_hol;

    i = 0;
	l_hol = elem->l;
	elem->a->single = 0;
	display(elem, gfx);
	elem->a->single = 1;
	(elem->l)++;
	while ((size_t)++i < elem->elem_nbr.l_nbr)
	{
		display(elem, gfx);
		(elem->l)++;
	}
	elem->l = l_hol;
}