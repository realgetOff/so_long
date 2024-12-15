/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:33:14 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 02:33:17 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j != 10)
	{
		i = 0;
		while (i != 10)
		{
			if (data->frame <= 30)
				mlx_put_image_to_window(data->mlx, data->win, data->env->b1, i
					* 640, j * 320);
			else if (data->frame <= 60)
				mlx_put_image_to_window(data->mlx, data->win, data->env->b2, i
					* 640, j * 320);
			else if (data->frame <= 90)
				mlx_put_image_to_window(data->mlx, data->win, data->env->b3, i
					* 640, j * 320);
			else
				mlx_put_image_to_window(data->mlx, data->win, data->env->b4, i
					* 640, j * 320);
			i++;
		}
		j++;
	}
}

void	handle_movement(t_data *data)
{
	if (data->move_up)
		display_movement_up(data);
	else if (data->move_down)
		display_movement_down(data);
	else if (data->move_left)
		display_movement_left(data);
	else if (data->move_right)
		display_movement_right(data);
	else
		display_movement_stand(data);
}

void	show_fail_message(t_data *data)
{
	if (data->fail > 5)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->env->standfck,
			data->x, data->y);
		mlx_string_put(data->mlx, data->win, data->x + 60, data->y, 0xFFFF0000,
			"Bon, concentre-toi !");
	}
}

void	show_start_screen(t_data *data)
{
	if ((data->start_button + data->move_up + data->move_down + data->move_left
			+ data->move_right) == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->env->start,
			(data->center_x - 655) / 2, (data->center_y - 120) / 2);
	}
}

int	display(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->frame = (data->frame + 1) % 120;
	mlx_clear_window(data->mlx, data->win);
	draw_background(data);
	init_map(data);
	init_score(data);
	check_game_over(data);
	show_start_screen(data);
	handle_movement(data);
	show_fail_message(data);
	return (0);
}
