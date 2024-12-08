/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:38:21 by mforest-          #+#    #+#             */
/*   Updated: 2024/12/02 00:39:47 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strvlen(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}
