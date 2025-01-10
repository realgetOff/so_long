/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:42:46 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 05:31:55 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_img_one(t_data *data)
{
	int	i;

	i = 0;
	while (i != 9)
	{
		if (data->env->score[i])
			mlx_destroy_image(data->mlx, data->env->score[i]);
		++i;
	}
	if (data->env->stand)
		mlx_destroy_image(data->mlx, data->env->stand);
	if (data->env->ship_exit)
		mlx_destroy_image(data->mlx, data->env->ship_exit);
	if (data->env->victory)
		mlx_destroy_image(data->mlx, data->env->victory);
	if (data->env->game_over)
		mlx_destroy_image(data->mlx, data->env->game_over);
	if (data->env->start)
		mlx_destroy_image(data->mlx, data->env->start);
	if (data->env->wall)
		mlx_destroy_image(data->mlx, data->env->wall);
	if (data->env->alan1)
		mlx_destroy_image(data->mlx, data->env->alan1);
	if (data->env->alan2)
		mlx_destroy_image(data->mlx, data->env->alan2);
}

static void	destroy_img_two(t_data *data)
{
	if (data->env->alan4)
		mlx_destroy_image(data->mlx, data->env->alan4);
	if (data->env->alan5)
		mlx_destroy_image(data->mlx, data->env->alan5);
	if (data->env->alan6)
		mlx_destroy_image(data->mlx, data->env->alan6);
	if (data->env->grunt_idle1)
		mlx_destroy_image(data->mlx, data->env->grunt_idle1);
	if (data->env->grunt_idle2)
		mlx_destroy_image(data->mlx, data->env->grunt_idle2);
	if (data->env->standfck)
		mlx_destroy_image(data->mlx, data->env->standfck);
	if (data->env->walk1)
		mlx_destroy_image(data->mlx, data->env->walk1);
	if (data->env->walk2)
		mlx_destroy_image(data->mlx, data->env->walk2);
	if (data->env->back1)
		mlx_destroy_image(data->mlx, data->env->back1);
	if (data->env->back2)
		mlx_destroy_image(data->mlx, data->env->back2);
	if (data->env->right1)
		mlx_destroy_image(data->mlx, data->env->right1);
	if (data->env->right2)
		mlx_destroy_image(data->mlx, data->env->right2);
}

void	destroy_data(t_data *data)
{
	if (data->env)
	{
		destroy_img_one(data);
		destroy_img_two(data);
		if (data->env->alan3)
			mlx_destroy_image(data->mlx, data->env->alan3);
		if (data->env->left1)
			mlx_destroy_image(data->mlx, data->env->left1);
		if (data->env->left2)
			mlx_destroy_image(data->mlx, data->env->left2);
		if (data->env->b1)
			mlx_destroy_image(data->mlx, data->env->b1);
		if (data->env->b2)
			mlx_destroy_image(data->mlx, data->env->b2);
		if (data->env->b3)
			mlx_destroy_image(data->mlx, data->env->b3);
		if (data->env->b4)
			mlx_destroy_image(data->mlx, data->env->b4);
	}
	else if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->env)
		free(data->env);
}

int	close_hook(int event, void *param)
{
	if (!event)
	{
		mlx_loop_end(param);
		ft_printf("\nYou left the game by force !\n");
		return (0);
	}
	return (1);
}

int	exit_hook(int key, t_data *data)
{
	if (key == 41)
	{
		mlx_loop_end(data->mlx);
		ft_printf("\nYou left the game by force !\n");
		return (0);
	}
	return (1);
}
