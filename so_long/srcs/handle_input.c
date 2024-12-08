/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:34:25 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 06:17:26 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->x / 64;
	map_y = data->y / 64;
	if (data->map_tab[map_y - 1][map_x] != WALL)
	{
		data->move_up = 1;
		data->y -= 64;
		data->sprite_toggle_up = !data->sprite_toggle_up;
		data->move++;
		ft_printf("You moved up ! [%d]\n", data->move);
		handle_interaction(data, map_x, map_y - 1);
		return (0);
	}
	ft_printf("You are trying to pass through a wall.\n");
	return (1);
}

int	move_down(t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->x / 64;
	map_y = data->y / 64;
	if (data->map_tab[map_y + 1][map_x] != WALL)
	{
		data->move_down = 1;
		data->y += 64;
		data->sprite_toggle_down = !data->sprite_toggle_down;
		data->move++;
		ft_printf("You moved down ! [%d]\n", data->move);
		handle_interaction(data, map_x, map_y + 1);
		return (0);
	}
	ft_printf("You are trying to pass through a wall.\n");
	return (1);
}

int	move_left(t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->x / 64;
	map_y = data->y / 64;
	if (data->map_tab[map_y][map_x + 1] != WALL)
	{
		data->move_left = 1;
		data->x += 64;
		data->sprite_toggle_left = !data->sprite_toggle_left;
		data->move++;
		ft_printf("You moved to the right ! [%d]\n", data->move);
		handle_interaction(data, map_x + 1, map_y);
		return (0);
	}
	ft_printf("You are trying to pass through a wall.\n");
	return (1);
}

int	move_right(t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = data->x / 64;
	map_y = data->y / 64;
	if (data->map_tab[map_y][map_x - 1] != WALL)
	{
		data->move_right = 1;
		data->x -= 64;
		data->sprite_toggle_right = !data->sprite_toggle_right;
		data->move++;
		ft_printf("You moved to the left ! [%d]\n", data->move);
		handle_interaction(data, map_x - 1, map_y);
		return (0);
	}
	ft_printf("You are trying to pass through a wall.\n");
	return (1);
}

int	key_hook(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->move_up = 0;
	data->move_down = 0;
	data->move_right = 0;
	data->move_left = 0;
	if (key_up(key, data) + key_down(key, data) + key_right(key, data)
		+ key_left(key, data))
	{
		data->fail++;
		data->start_button++;
	}
	exit_hook(key, data);
	return (0);
}
