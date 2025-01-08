/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:06:30 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 06:22:41 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_score(t_data *data, int score, int base)
{
	mlx_put_image_to_window(data->mlx, data->win, data->env->score[score], base,
		0);
}

int	init_score(t_data *data)
{
	int	ones;
	int	tens;
	int	hundreds;
	int	window_width;
	int	spacing;

	window_width = ft_strlen(data->map_tab[0]) * 59;
	spacing = 60;
	ones = data->move % 10;
	tens = (data->move / 10) % 10;
	hundreds = (data->move / 100) % 10;
	draw_score(data, hundreds, window_width - spacing * 2);
	draw_score(data, tens, window_width - spacing);
	draw_score(data, ones, window_width - 0);
	if (data->move > 999)
		data->game_over++;
	return (0);
}

int	check_game_over(t_data *data)
{
	if (data->game_over)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->env->game_over,
			(data->center_x - 490) / 2, (data->center_y - 75) / 2);
		if (data->frame == 30 || data->frame == 90)
		{
			if (data->alan)
				ft_printf("You did not collect all the collectibles !\n");
			if (!data->alan)
				ft_printf("You got killed by Grunt !\n");
			sleep(3);
			mlx_loop_end(data->mlx);
		}
	}
	return (0);
}
