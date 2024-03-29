/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:13:03 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/24 10:22:00 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**floodfill(char **map, int y, int x, char dir)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'F')
		return (map);
	map[y][x] = 'F';
	if (dir != 'd')
		map = floodfill(map, y - 1, x, 'u');
	if (dir != 'u')
		map = floodfill(map, y + 1, x, 'd');
	if (dir != 'r')
		map = floodfill(map, y, x - 1, 'l');
	if (dir != 'l')
		map = floodfill(map, y, x + 1, 'r');
	return (map);
}

// check if exit can be reached and coins can be collected
int	valid_path(char **map)
{
	char	**copy;
	t_point	start;
	t_point	size;

	copy = copy_map(map);
	if (!copy)
		return (0);
	start = get_begin(copy, 'P');
	size = get_size(copy);
	copy = floodfill(copy, start.y, start.x, ' ');
	if (!count_char(copy, 'E') && !count_char(copy, 'C'))
	{
		free_all(copy);
		return (1);
	}
	write(2, "Error\nno path found\n", 20);
	free_all(copy);
	return (0);
}
