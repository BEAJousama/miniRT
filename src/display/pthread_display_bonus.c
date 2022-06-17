/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 09:58:46 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	*pthread_display(void *pinfo_ptr)
{
	int		x;
	int		y;
	int		line;
	t_cogo	ray;
	double	p_stp;
	double	x_ray_hol;
	t_pth_ptr   *pinfo;

	y = -1;
	pinfo = pinfo_ptr;
	line = pinfo->line;
	init_ray(pinfo->elem, &ray);
	p_stp = fabs(ray.x * 2) / 1000;
	x_ray_hol = ray.x;
	ray.y -= line * p_stp;
	while (++y < 100)
	{
		x = -1;
		ray.x = x_ray_hol;
		while (++x < 1000)
		{
			ray.x += p_stp;
			fill_color_buffer(pinfo->gfx, get_pixel_color(pinfo->elem, ray, p_stp, 1), x, line);
		}
		ray.y -= p_stp;
		line++;
	}
	return (NULL);
}

void	create_thrads(t_elements *elem, t_mlx_ptr *gfx)
{
    pthread_t   pth[10];
    t_pth_ptr   pinfo;
    int         i;

    pinfo.elem = elem;
    pinfo.gfx = gfx;
    i = -1;
    while (++i < 10)
	{
        pinfo.line = 100 * i;
		pthread_create(&pth[i], NULL, pthread_display, (void *)&pinfo);
		usleep(100);
	}
	i = -1;
	while (++i < 10)
		pthread_join(pth[i], NULL);

}
