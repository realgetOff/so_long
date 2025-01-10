/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:16:43 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 05:44:50 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_until(t_data *data, char *img, char word)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (data->map_tab[map_y])
	{
		map_x = 0;
		while (data->map_tab[map_y][map_x])
		{
			if (data->map_tab[map_y][map_x] == word)
				mlx_put_image_to_window(data->mlx, data->win, img, map_x
					* TILE_SIZE, map_y * TILE_SIZE);
			map_x++;
		}
		map_y++;
	}
}

int	init_map(t_data *data)
{
	check_map_until(data, data->env->wall, WALL);
	if (data->frame <= 60)
		check_map_until(data, data->env->grunt_idle1, GRUNT);
	else if (data->frame <= 120)
		check_map_until(data, data->env->grunt_idle2, GRUNT);
	if (data->frame <= 15)
		check_map_until(data, data->env->alan1, ALAN);
	else if (data->frame <= 30)
		check_map_until(data, data->env->alan2, ALAN);
	else if (data->frame <= 45)
		check_map_until(data, data->env->alan3, ALAN);
	else if (data->frame <= 55)
		check_map_until(data, data->env->alan4, ALAN);
	else if (data->frame <= 90)
		check_map_until(data, data->env->alan5, ALAN);
	else if (data->frame <= 120)
		check_map_until(data, data->env->alan6, ALAN);
	check_map_until(data, data->env->ship_exit, EXIT);
	init_startpos(data);
	init_exit(data);
	return (0);
}

int	init_startpos(t_data *data)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (data->map_tab[map_y])
	{
		map_x = 0;
		while (data->map_tab[map_y][map_x])
		{
			if (data->map_tab[map_y][map_x] == START_POS && (data->start_button
					+ data->move_up + data->move_down + data->move_left
					+ data->move_right) == 0)
			{
				mlx_put_image_to_window(data->mlx, data->win, data->env->stand,
					map_x * TILE_SIZE, map_y * TILE_SIZE);
				data->y = map_y * TILE_SIZE;
				data->x = map_x * TILE_SIZE;
			}
			map_x++;
		}
		map_y++;
	}
	return (0);
}

int	init_exit(t_data *data)
{
	if (data->victory)
	{
		if (data->alan)
			data->game_over++;
		if (!data->alan)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->env->victory,
				(data->center_x - 500) / 2, (data->center_y - 360) / 2);
			if (data->frame == 30 || data->frame == 90)
			{
				ft_printf("You won !\n");
				ft_printf("With a total of : [%d] !\n", data->move);
				sleep(3);
				mlx_loop_end(data->mlx);
			}
		}
	}
	return (0);
}
