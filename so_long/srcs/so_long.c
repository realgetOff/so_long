/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:43:48 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 06:22:55 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (init_data(&data, av[1]))
		{
			destroy_data(&data);
			return (1);
		}
		mlx_set_font_scale(data.mlx, data.win, "textures/font.ttf", 18.0f);
		mlx_on_event(data.mlx, data.win, MLX_WINDOW_EVENT, close_hook,
			data.mlx);
		mlx_on_event(data.mlx, data.win, MLX_KEYDOWN, key_hook, &data);
		mlx_loop_hook(data.mlx, display, &data);
		mlx_set_fps_goal(data.mlx, FPS);
		mlx_loop(data.mlx);
		destroy_data(&data);
		return (0);
	}
	else
		ft_printf("Error\nNeed two args!\n");
	return (0);
}
