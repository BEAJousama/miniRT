/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_opp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:54:15 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/26 17:54:17 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void    comlete_rotation_y(double x, double z, double *ang)
{
    if (x < 0 && z >= 0)
        (*ang) = (2 * M_PI) - (*ang);
    else if (x > 0 && z < 0)
        (*ang) =  M_PI - (*ang);
    else if (x <= 0 && z < 0)
        (*ang) =   M_PI + (*ang);
}

void    comlete_rotation_x(double y, double z, double *ang)
{
    if (y > 0 && z >= 0)
       (*ang) = (2 * M_PI) - (*ang);
    else if (y > 0 && z < 0)
        (*ang) =  M_PI + (*ang);
    else if (y < 0 && z < 0)
        (*ang) =   M_PI - (*ang);
}

void    fill_sub_matrix(t_elements *elem, double **t_y, double **t_x)
{
    double  teta=0;
    double  beta=0;

    if (elem->c->orient.x || elem->c->orient.z)
        teta = (acos(fabs(elem->c->orient.z) / sqrt(pow(elem->c->orient.z, 2)
            + pow(elem->c->orient.x, 2))));
    comlete_rotation_y(elem->c->orient.x, elem->c->orient.z, &teta);
    t_y[0][0] = cos(teta);
    t_y[0][2] = sin(teta);
    t_y[1][1] = 1;
    t_y[2][0] = -sin(teta);
    t_y[2][2] = cos(teta);
    t_y[3][3] = 1;
    elem->c->orient.z = fabs(elem->c->orient.z);
    beta =  (acos(sqrt(pow(mag_vector(elem->c->orient),2)
        - pow(elem->c->orient.y, 2)) / mag_vector(elem->c->orient)));
    comlete_rotation_x(elem->c->orient.y, elem->c->orient.z, &beta);
    t_x[0][0] = 1;
    t_x[1][1] = cos(beta);
    t_x[1][2] = -sin(beta);
    t_x[2][1] = sin(beta);
    t_x[2][2] = cos(beta);
    t_x[3][3] = 1;
}


void    fill_main_matrix(double **t_pos, double **t_y, double **t_x)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        t_pos[i][j] = (t_y[i][0] * t_x[0][j]) + (t_y[i][1] * t_x[1][j])
            + (t_y[i][2] * t_x[2][j]) + (t_y[i][3] * t_x[3][j]);
        if (++j == 4 && ++i)
            j = 0;
    }
}