/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:20:57 by qdang             #+#    #+#             */
/*   Updated: 2019/11/01 15:03:07 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void	chart_dots(char **chart, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			chart[i][j] = '.';
			j++;
		}
		i++;
	}
}

static int	chart_check(char **chart, t_map now, t_point ini)
{
	int		i;
	int		j;

	i = 0;
	while (i < now.size.x)
	{
		j = 0;
		while (j < now.size.y)
		{
			if (chart[ini.x + i][ini.y + j] != '.' &&
					now.map[now.start.x + i][now.start.y + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	chart_fillblock(char ***chart_a, t_map now, t_point ini)
{
	int		i;
	int		j;

	if (chart_check(*chart_a, now, ini) == 0)
		return (0);
	i = 0;
	while (i < now.size.x)
	{
		j = 0;
		while (j < now.size.y)
		{
			if ((*chart_a)[ini.x + i][ini.y + j] == '.')
				(*chart_a)[ini.x + i][ini.y + j] =
					now.map[now.start.x + i][now.start.y + j];
			j++;
		}
		i++;
	}
	return (1);
}

static int	chart_fill(char ***chart_a, int sl, t_map *all, int nb)
{
	int		i;
	int		j;
	t_map	now;
	char	**temp;
	t_point	ini;

	now = all[nb];
	i = 0;
	temp = ft_mapcpy(*chart_a, sl, sl);
	while (i < sl && i + now.size.x <= sl)
	{
		j = 0;
		while (j < sl && j + now.size.y <= sl)
		{
			ini.x = i;
			ini.y = j;
			if (chart_fillblock(chart_a, now, ini) == 1)
			{
				if (nb + 1 >= all[0].count)
					return (1);
				else
				{
					if (chart_fill(chart_a, sl, all, nb + 1) == 1)
						return (1);
					else
						*chart_a = ft_mapcpy(temp, sl, sl);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		chart_output(t_map *all, int count)
{
	int		sl;
	char	**chart;

	sl = 2;
	while (sl * sl < count * 4)
		sl++;
	chart = ft_mapnew(sl, sl);
	chart_dots(chart, sl);
	while (chart_fill(&chart, sl, all, 0) == 0)
	{
		sl++;
		chart = ft_mapnew(sl, sl);
		chart_dots(chart, sl);
	}
	ft_mapput(chart, sl, sl);
}
