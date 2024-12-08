/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:03:24 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 02:09:27 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_movement_up(t_data *data)
{
	if (data->sprite_toggle_up)
		mlx_put_image_to_window(data->mlx, data->win, data->env->walk1, data->x,
			data->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->env->walk2, data->x,
			data->y);
}

void	display_movement_down(t_data *data)
{
	if (data->sprite_toggle_down)
		mlx_put_image_to_window(data->mlx, data->win, data->env->back1, data->x,
			data->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->env->back2, data->x,
			data->y);
}

void	display_movement_left(t_data *data)
{
	if (data->sprite_toggle_left)
		mlx_put_image_to_window(data->mlx, data->win, data->env->left1, data->x,
			data->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->env->left2, data->x,
			data->y);
}

void	display_movement_right(t_data *data)
{
	if (data->sprite_toggle_right)
		mlx_put_image_to_window(data->mlx, data->win, data->env->right1,
			data->x, data->y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->env->right2,
			data->x, data->y);
}

void	display_movement_stand(t_data *data)
{
	if (data->env->stand)
		mlx_put_image_to_window(data->mlx, data->win, data->env->stand, data->x,
			data->y);
}
