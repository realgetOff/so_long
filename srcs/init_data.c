/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:07:20 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/08 19:37:42 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window_and_env(t_data *data)
{
	t_environment	*env_tmp;

	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, ft_strlen(data->map_tab[0]) * 64,
			ft_strvlen(data->map_tab) * 64, "so_long");
	if (!data->win)
		return (1);
	data->center_x = ft_strlen(data->map_tab[0]) * 64;
	data->center_y = ft_strvlen(data->map_tab) * 64;
	env_tmp = ft_calloc(sizeof(t_environment), 1);
	if (!env_tmp)
		return (1);
	data->env = env_tmp;
	if (init_background(data, data->env) || init_sprites(data, data->env)
		|| init_assets(data, data->env) || init_assets_score(data, data->env))
		return (1);
	return (0);
}

int	init_data(t_data *data, char *filename)
{
	ft_bzero(data, sizeof(t_data));
	data->map = get_contents(filename);
	if (!data->map)
		return (1);
	data->alan = ft_count(data->map, 'C');
	data->count_c = ft_count(data->map, 'C');
	data->count_p = ft_count(data->map, 'P');
	data->count_g = ft_count(data->map, 'G');
	data->count_e = ft_count(data->map, 'E');
	data->map_tab = ft_split(data->map, '\n');
	if (map_core(filename, data))
		return (1);
	if (find_path(0, -1, -1, data))
		return (1);
	if (!data->map_tab)
		return (1);
	if (!init_window_and_env(data))
		return (1);
	return (0);
}
