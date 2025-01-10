/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:28:01 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 05:57:23 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_image(t_data *data, t_environment *env_data, char *path,
		void **image)
{
	int	width;
	int	height;

	(void)env_data;
	*image = mlx_png_file_to_image(data->mlx, path, &width, &height);
	if (*image == NULL)
		return (1);
	return (0);
}

int	init_background(t_data *data, t_environment *env_data)
{
	if (load_image(data, env_data, "textures/b1.png", &env_data->b1) != 0)
		return (1);
	if (load_image(data, env_data, "textures/ship_exit.png",
			&env_data->ship_exit) != 0)
		return (1);
	if (load_image(data, env_data, "textures/b2.png", &env_data->b2) != 0)
		return (1);
	if (load_image(data, env_data, "textures/b3.png", &env_data->b3) != 0)
		return (1);
	if (load_image(data, env_data, "textures/b4.png", &env_data->b4) != 0)
		return (1);
	if (load_image(data, env_data, "textures/wall.png", &env_data->wall) != 0)
		return (1);
	if (load_image(data, env_data, "textures/start.png", &env_data->start) != 0)
		return (1);
	if (load_image(data, env_data, "textures/game_over.png",
			&env_data->game_over) != 0)
		return (1);
	if (load_image(data, env_data, "textures/victory.png",
			&env_data->victory) != 0)
		return (1);
	return (0);
}

int	init_sprites(t_data *data, t_environment *env_data)
{
	if (load_image(data, env_data, "textures/stand.png", &env_data->stand) != 0)
		return (1);
	if (load_image(data, env_data, "textures/standfck.png",
			&env_data->standfck) != 0)
		return (1);
	if (load_image(data, env_data, "textures/walk1.png", &env_data->walk1) != 0)
		return (1);
	if (load_image(data, env_data, "textures/walk2.png", &env_data->walk2) != 0)
		return (1);
	if (load_image(data, env_data, "textures/back1.png", &env_data->back1) != 0)
		return (1);
	if (load_image(data, env_data, "textures/back2.png", &env_data->back2) != 0)
		return (1);
	if (load_image(data, env_data, "textures/right1.png",
			&env_data->right1) != 0)
		return (1);
	if (load_image(data, env_data, "textures/right2.png",
			&env_data->right2) != 0)
		return (1);
	if (load_image(data, env_data, "textures/left1.png", &env_data->left1) != 0)
		return (1);
	if (load_image(data, env_data, "textures/left2.png", &env_data->left2) != 0)
		return (1);
	return (0);
}

int	init_assets(t_data *data, t_environment *env_data)
{
	if (load_image(data, env_data, "textures/grunt_idle1.png",
			&env_data->grunt_idle1) != 0)
		return (1);
	if (load_image(data, env_data, "textures/grunt_idle2.png",
			&env_data->grunt_idle2) != 0)
		return (1);
	if (load_image(data, env_data, "textures/alan1.png", &env_data->alan1) != 0)
		return (1);
	if (load_image(data, env_data, "textures/alan2.png", &env_data->alan2) != 0)
		return (1);
	if (load_image(data, env_data, "textures/alan3.png", &env_data->alan3) != 0)
		return (1);
	if (load_image(data, env_data, "textures/alan4.png", &env_data->alan4) != 0)
		return (1);
	if (load_image(data, env_data, "textures/alan5.png", &env_data->alan5) != 0)
		return (1);
	if (load_image(data, env_data, "textures/alan6.png", &env_data->alan6) != 0)
		return (1);
	return (0);
}

int	init_assets_score(t_data *data, t_environment *env)
{
	int			i;
	const char	*img_lst[10] = {"textures/zero.png", "textures/one.png",
		"textures/two.png", "textures/three.png", "textures/four.png",
		"textures/five.png", "textures/six.png", "textures/seven.png",
		"textures/eight.png", "textures/nine.png"};

	i = 0;
	while (i != 10)
	{
		env->score[i] = mlx_png_file_to_image(data->mlx, (char *)img_lst[i],
				NULL, NULL);
		i++;
	}
	i = 0;
	while (i != 10 && env->score[i] != NULL)
		i++;
	return (i == 10);
}
