/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 05:12:32 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 06:24:24 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_col(t_data *data)
{
	int	map_y;
	int	map_x;

	map_y = 0;
	while (data->map_tab[map_y])
	{
		if (data->map_tab[map_y][0] != WALL)
		{
			ft_printf("Error\nColumn not closed\n");
			return (1);
		}
		map_x = 0;
		while (data->map_tab[map_y][map_x])
		{
			map_x++;
		}
		if (data->map_tab[map_y][map_x - 1] != WALL)
		{
			ft_printf("Error\nColumn not closed\n");
			return (1);
		}
		map_y++;
	}
	return (0);
}

int	ft_check_line(t_data *data)
{
	int	map_y;

	if (data->count_e > 1 || data->count_p > 1)
	{
		ft_printf("Error\nToo much exit and/or starting pos\n");
		return (1);
	}
	map_y = 0;
	while (data->map_tab[map_y])
	{
		if (ft_check_line_edges(data, map_y))
			return (1);
		map_y++;
	}
	return (0);
}

int	ft_check_line_edges(t_data *data, int map_y)
{
	int	map_x;

	map_x = 0;
	if (map_y == 0 || data->map_tab[map_y + 1] == NULL)
	{
		while (data->map_tab[map_y][map_x])
		{
			if (data->map_tab[map_y][map_x] != WALL)
			{
				ft_printf("Error\nLine not closed\n");
				return (1);
			}
			map_x++;
		}
	}
	return (0);
}

int	ft_check_other(t_data *data)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (data->map_tab[map_y])
	{
		map_x = 0;
		while (data->map_tab[map_y][map_x])
		{
			if (data->map_tab[map_y][map_x] != WALL
				&& data->map_tab[map_y][map_x] != START_POS
				&& data->map_tab[map_y][map_x] != EXIT
				&& data->map_tab[map_y][map_x] != ALAN
				&& data->map_tab[map_y][map_x] != GRUNT
				&& data->map_tab[map_y][map_x] != SPACE)
			{
				ft_printf("Error\nUnkown symbols in map\n");
				return (1);
			}
			map_x++;
		}
		map_y++;
	}
	return (0);
}

int	ft_check_format(t_data *data)
{
	int		map_y;
	size_t	count_x;

	count_x = ft_strlen(data->map_tab[0]);
	map_y = 0;
	while (data->map_tab[map_y])
	{
		if (ft_strlen(data->map_tab[map_y]) != count_x)
		{
			ft_printf("Error\nMap isn't a square or a rectangle\n");
			return (1);
		}
		map_y++;
	}
	return (0);
}
