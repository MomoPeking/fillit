/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:20:57 by qdang             #+#    #+#             */
/*   Updated: 2019/11/07 21:09:48 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static int	chart_check(char **chart, t_map now, int ini_x, int ini_y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < now.size.x)
	{
		j = -1;
		while (++j < now.size.y)
		{
			if (chart[ini_x + i][ini_y + j] != '.' &&
					now.map[now.start.x + i][now.start.y + j] != '.')
				return (0);
		}
	}
	return (1);
}

static int	chart_fillblock(char ***chart_a, t_map now, int ini_x, int ini_y)
{
	int		i;
	int		j;

	if (chart_check(*chart_a, now, ini_x, ini_y) == 0)
		return (0);
	i = -1;
	while (++i < now.size.x)
	{
		j = -1;
		while (++j < now.size.y)
		{
			if ((*chart_a)[ini_x + i][ini_y + j] == '.')
				(*chart_a)[ini_x + i][ini_y + j] =
					now.map[now.start.x + i][now.start.y + j];
		}
	}
	return (1);
}

void		chart_dots(char ***chart_a, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			(*chart_a)[i][j] = '.';
	}
}

int			chart_fill(char ***chart_a, int sl, t_map *all, int nb)
{
	int		i;
	int		j;
	char	**temp;

	i = -1;
	temp = ft_mapcpy(*chart_a, sl, sl);
	while (++i < sl && i + all[nb].size.x <= sl)
	{
		j = -1;
		while (++j < sl && j + all[nb].size.y <= sl)
		{
			if (chart_fillblock(chart_a, all[nb], i, j) == 1)
			{
				if (nb + 1 >= all[0].count
						|| chart_fill(chart_a, sl, all, nb + 1) == 1)
					return (ft_mapdel(&temp, sl) + 1);
				ft_mapdel(chart_a, sl);
				*chart_a = ft_mapcpy(temp, sl, sl);
			}
		}
	}
	return (ft_mapdel(&temp, sl));
}
