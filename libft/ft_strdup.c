/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:58:17 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 05:58:19 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		a;
	char	*ctrlv;

	a = 0;
	while (s[a])
		a++;
	ctrlv = (char *)malloc((a + 1) * (sizeof(char)));
	if (!ctrlv)
		return (NULL);
	a = 0;
	while (s[a])
	{
		ctrlv[a] = s[a];
		a++;
	}
	ctrlv[a] = '\0';
	return (ctrlv);
}
