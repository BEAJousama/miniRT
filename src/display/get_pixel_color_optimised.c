/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 14:45:58 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int recursion_condition(t_elements *elem, t_cogo ray, double pixel_step, bool depth)
{
    int color;

    if (depth)
		color = get_pixel_color(elem, ray, pixel_step / 2, 0);
	else
		color = check_intersection(elem, ray);
    return (color);
}

int	get_pixel_color(t_elements *elem, t_cogo ray, double pixel_step, bool depth)
{
	int	color;
	int	color_h;

	ray.x -= (pixel_step) / 4;
	ray.y += (pixel_step) / 4;
    color = recursion_condition(elem, ray, pixel_step, depth);
	ray.x += (pixel_step) / 2;
    color_h = recursion_condition(elem, ray, pixel_step, depth);
	color = mean_rgb(color, color_h);
	ray.x -= (pixel_step) / 2;
	ray.y -= (pixel_step) / 2;
    color_h = recursion_condition(elem, ray, pixel_step, depth);
	color = mean_rgb(color, color_h);
	ray.x += (pixel_step) / 2;
    color_h = recursion_condition(elem, ray, pixel_step, depth);
	color = mean_rgb(color, color_h);
	return (color);
}