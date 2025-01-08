/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:29:50 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 06:18:23 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_interaction(t_data *data, int map_x, int map_y)
{
	if (data->map_tab[map_y][map_x] == ALAN)
	{
		ft_printf("You got Alan back !\n");
		data->alan--;
		data->map_tab[map_y][map_x] = '0';
	}
	else if (data->map_tab[map_y][map_x] == GRUNT)
		data->game_over++;
	else if (data->map_tab[map_y][map_x] == EXIT)
		data->victory++;
}

int	key_up(int key, t_data *data)
{
	if (key == Up && !data->game_over && !data->victory)
	{
		data->fail = 0;
		return (move_up(data));
	}
	return (1);
}

int	key_down(int key, t_data *data)
{
	if (key == Down && !data->game_over && !data->victory)
	{
		data->fail = 0;
		return (move_down(data));
	}
	return (1);
}

int	key_left(int key, t_data *data)
{
	if (key == Left && !data->game_over && !data->victory)
	{
		data->fail = 0;
		return (move_left(data));
	}
	return (1);
}

int	key_right(int key, t_data *data)
{
	if (key == Right && !data->game_over && !data->victory)
	{
		data->fail = 0;
		return (move_right(data));
	}
	return (1);
}
