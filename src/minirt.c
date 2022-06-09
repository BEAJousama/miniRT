/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:18:35 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/17 11:11:06 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void    print_info(t_elements elem)
{
    int i;
    
    i = -1;
    while (++i < (int)elem.elem_nbr.a_nbr)
        printf(" A: %-10.5f %d\n", elem.a[i].ratio, elem.a[i].rgb);
    i = -1;
    while (++i < (int)elem.elem_nbr.c_nbr)
        printf(" C: %.1f,%.1f,%-10.1f %.1f,%.1f,%.1f       %.1f\n", elem.c[i].pos.x, elem.c[i].pos.y, elem.c[i].pos.z,  elem.c[i].orient.x, elem.c[i].orient.y, elem.c[i].orient.z, elem.c[i].fov);
    i = -1;
    while (++i < (int)elem.elem_nbr.l_nbr)    
        printf(" L: %.1f,%.1f,%-10.f %.5f               %d\n",elem.l[i].pos.x, elem.l[i].pos.y, elem.l[i].pos.z,   elem.l[i].bright, elem.l[i].rgb);
    i = -1;
    while (++i < (int)elem.elem_nbr.pl_nbr)
        printf("pl: %.1f,%.1f,%-10.1f   %.1f,%.1f,%.1f       %d\n",  elem.pl[i].pos.x, elem.pl[i].pos.y, elem.pl[i].pos.z,  elem.pl[i].orient.x, elem.pl[i].orient.y, elem.pl[i].orient.z, elem.pl[i].rgb);
    i = -1;
    while (++i < (int)elem.elem_nbr.sp_nbr)
        printf("sp: %.1f,%.1f,%-10.1f   %.1f              %d\n",    elem.sp[i].pos.x, elem.sp[i].pos.y, elem.sp[i].pos.z, elem.sp[i].diameter, elem.sp[i].rgb);
    i = -1;
    while (++i < (int)elem.elem_nbr.cy_nbr)
        printf("cy: %.1f,%.1f,%-10.1f  %.1f,%.1f,%.1f       %.2f       %.2f       %d\n",elem.cy[i].pos.x, elem.cy[i].pos.y, elem.cy[i].pos.z,  elem.cy[i].orient.x, elem.cy[i].orient.y, elem.cy[i].orient.z, elem.cy[i].diameter, elem.cy[i].height,  elem.cy[i].rgb);
}

int	close_win(t_elements *elem)
{
	free_elements(elem);
	exit(0);
	return (0);
}

int	close_win_esc(int keycode, t_elements *elem)
{
	if (keycode == ESC_KEY)
	{
		free_elements(elem);
		exit(0);
	}
	return (0);
}

void	free_elements(t_elements *elem)
{
	int	i;

	i = -1;
	free(elem->a);
	free(elem->c);
	free(elem->l);
	free(elem->sp);
	free(elem->pl);
	free_matrix(elem->m_pos, 4);
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		free_matrix(elem->cy[i].m_pos, 4);
	free(elem->cy);
}

int	main(int ac, char **av)
{
	t_elements	elem;
	t_mlx_ptr	gfx;

	(void)av;
	elem = (t_elements){};
	gfx = (t_mlx_ptr){};
	if (ac != 2)
		map_invalid(INVALID_N_ARGS);
	read_map(&elem, av[1]);
	gfx.mlx = mlx_init();
	gfx.win = mlx_new_window(gfx.mlx, 1000, 1000, NAME_W);
	gfx.img = mlx_new_image(gfx.mlx, 1000, 1000);
	gfx.buf = mlx_get_data_addr(gfx.img, &gfx.p_bits, &gfx.l_bytes, &gfx.endian);
	display(&elem, &gfx);
	mlx_put_image_to_window(gfx.mlx, gfx.win, gfx.img, 0, 0);
	// print_info(elem);
	mlx_hook(gfx.win, 2, 0L, close_win_esc, &elem);
	mlx_hook(gfx.win, 17, 0L, close_win, &elem);
	mlx_loop(gfx.mlx);
	free_elements(&elem);
	return (0);
}

