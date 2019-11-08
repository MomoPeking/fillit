/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:17:20 by qdang             #+#    #+#             */
/*   Updated: 2019/11/07 18:37:55 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static t_point	block_size(char **map)
{
	int		w;
	int		h;
	int		i;
	t_point	ans;

	w = 4;
	h = 4;
	i = 0;
	while (i <= 3)
	{
		if (map[0][i] == '.' && map[1][i] == '.' &&
				map[2][i] == '.' && map[3][i] == '.')
			w--;
		if (map[i][0] == '.' && map[i][1] == '.' &&
				map[i][2] == '.' && map[i][3] == '.')
			h--;
		i++;
	}
	ans.x = h;
	ans.y = w;
	return (ans);
}

static t_point	block_start(char **map)
{
	int		i;
	int		j;
	t_point	ans;

	i = 0;
	j = 0;
	while (map[0][j] == '.' && map[1][j] == '.' &&
				map[2][j] == '.' && map[3][j] == '.')
		j++;
	while (map[i][0] == '.' && map[i][1] == '.' &&
				map[i][2] == '.' && map[i][3] == '.')
		i++;
	ans.x = i;
	ans.y = j;
	return (ans);
}

static char		**store_map(char *buff, int sn)
{
	char	**map;
	int		i;

	map = ft_mapnew(4, 4);
	i = 0;
	while (i <= 18)
	{
		if (i % 5 == 4)
			i++;
		if (buff[i] == '#')
			buff[i] = 'A' + sn;
		map[i / 5][i % 5] = buff[i];
		i++;
	}
	return (map);
}

t_map			*store_all(int fd, int count)
{
	int		sn;
	t_map	*all;
	char	buff[21];

	sn = 0;
	all = (t_map *)malloc(sizeof(t_map) * count);
	while (sn < count)
	{
		read(fd, buff, 21);
		all[sn].count = count;
		all[sn].map = store_map(buff, sn);
		all[sn].start = block_start(all[sn].map);
		all[sn].size = block_size(all[sn].map);
		sn++;
	}
	return (all);
}
