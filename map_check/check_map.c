/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:28:38 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/15 14:55:55 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangle(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			write(2, "map is not rectangular\n", 23);
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_char(char **map, char c)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

int	characters(char **map)
{
	if (count_char(map, 'P') != 1
		|| count_char(map, 'E') != 1
		|| count_char(map, 'C') < 1)
	{
		write(2, "incorrect characters in map\n", 28);
		return (0);
	}
	return (1);
}

int	only_c(char *str, char c)
{
	while (str && *str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

int	wall(char **map)
{
	int	i;
	int	size[2];

	i = 0;
	size[0] = 0;
	size[1] = ft_strlen(map[0]);
	while (map[size[0]])
		size[0]++;
	if (!only_c(map[0], '1') || !only_c(map[size[0] - 1], '1'))
	{
		write(2, "map must be surrounded by walls\n", 32);
		return (0);
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][size[1] - 1] != '1')
		{
			write(2, "map must be surrounded by walls\n", 32);
			return (0);
		}
		i++;
	}
	return (1);
}
