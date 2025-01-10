/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 04:43:36 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 05:48:46 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid(int x, int y, int **visited, t_data *data)
{
	if ((x >= 0 && x < 100) && (y >= 0 && y < 100) && data->map_tab[x]
		&& data->map_tab[x][y] != WALL && visited[x][y] == 0)
		return (0);
	return (1);
}

static int	dfs(int x, int y, int **visited, t_data *data)
{
	if (data->map_tab[x][y] == EXIT)
		return (0);
	visited[x][y] = 1;
	if (!is_valid(x - 1, y, visited, data))
		if (!dfs(x - 1, y, visited, data))
			return (0);
	if (!is_valid(x + 1, y, visited, data))
		if (!dfs(x + 1, y, visited, data))
			return (0);
	if (!is_valid(x, y - 1, visited, data))
		if (!dfs(x, y - 1, visited, data))
			return (0);
	if (!is_valid(x, y + 1, visited, data))
		if (!dfs(x, y + 1, visited, data))
			return (0);
	return (1);
}

static int	**tab_alloc(size_t alloc)
{
	int		**tab;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	tab = (int **)ft_calloc(alloc, sizeof(int *));
	if (!tab)
		return (NULL);
	while (j < alloc)
	{
		tab[j] = (int *)ft_calloc(alloc, sizeof(int));
		if (!tab[j])
		{
			while (k < j)
				free(tab[k++]);
			free(tab);
			return (NULL);
		}
		j++;
	}
	return (tab);
}

static void	start_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_tab[i])
	{
		j = 0;
		while (data->map_tab[i][j])
		{
			if (data->map_tab[i][j] == START_POS)
			{
				data->start_x = i;
				data->start_y = j;
			}
			j++;
		}
		i++;
	}
}

int	find_path(t_data *data)
{
	int	**visited;

	data->start_y = 0;
	data->start_x = 0;
	visited = tab_alloc(100);
	if (!visited)
		return (1);
	start_pos(data);
	if (dfs(data->start_x, data->start_y, visited, data) == 0)
	{
		ft_free_tab(visited, 100);
		return (0);
	}
	ft_perror("There is no valid path");
	ft_free_tab(visited, 100);
	return (1);
}
