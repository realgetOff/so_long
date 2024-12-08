/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 04:43:36 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 06:26:20 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(int x, int y, int visited[1000][1000], t_data *data)
{
	if (x >= 0 && y >= 0 && data->map_tab[x] && data->map_tab[x][y] != WALL
		&& visited[x][y] == 0)
		return (0);
	return (1);
}

int	dfs(int x, int y, int visited[1000][1000], t_data *data)
{
	if (data->map_tab[x][y] == EXIT)
		return (0);
	visited[x][y] = 1;
	if (!is_valid(x - 1, y, visited, data))
	{
		if (!dfs(x - 1, y, visited, data))
			return (0);
	}
	if (!is_valid(x + 1, y, visited, data))
	{
		if (!dfs(x + 1, y, visited, data))
			return (0);
	}
	if (!is_valid(x, y - 1, visited, data))
	{
		if (!dfs(x, y - 1, visited, data))
			return (0);
	}
	if (!is_valid(x, y + 1, visited, data))
	{
		if (!dfs(x, y + 1, visited, data))
			return (0);
	}
	return (1);
}

void	init_visited(int visited[1000][1000], t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_tab[i])
	{
		j = 0;
		while (data->map_tab[i][j])
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	find_path(int i, int start_y, int start_x, t_data *data)
{
	int	j;
	int	visited[1000][1000];

	while (data->map_tab[i])
	{
		j = 0;
		while (data->map_tab[i][j])
		{
			if (data->map_tab[i][j] == START_POS)
			{
				start_x = i;
				start_y = j;
			}
			j++;
		}
		i++;
	}
	init_visited(visited, data);
	if (!dfs(start_x, start_y, visited, data))
		return (0);
	else
	{
		ft_printf("Error\nThere is no valid path !\n");
		return (1);
	}
}
