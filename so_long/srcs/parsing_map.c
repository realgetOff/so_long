/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:54:01 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/07 06:20:11 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_tab[i])
	{
		free(data->map_tab[i]);
		i++;
	}
	free(data->map_tab);
	data->map_tab = NULL;
	return (1);
}

int	parse_map(t_data *data)
{
	if (ft_check_format(data))
		return (1);
	if (ft_check_line(data))
		return (1);
	if (ft_check_col(data))
		return (1);
	if (ft_check_other(data))
		return (1);
	if (ft_check_line(data))
		return (1);
	return (0);
}

char	map_core(char *str, t_data *data)
{
	data->map_tab = ft_split(data->map, '\n');
	if (has_suffix(str, ".ber"))
	{
		ft_printf("Error\nBad map format\n");
		return (1);
	}
	if (parse_map(data))
		return (1);
	if ((!data->count_c || data->count_e != 1 || data->count_p != 1)
		&& data->map_tab)
	{
		ft_free_map(data);
		ft_printf("Error\nMiss exit and/or starting pos and/or collectibles\n");
		return (1);
	}
	return (0);
}
