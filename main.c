/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:56:56 by qdang             #+#    #+#             */
/*   Updated: 2019/11/07 21:13:58 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void	all_put(t_map *all)
{
	int		sl;
	char	**chart;

	sl = 2;
	while (sl * sl < all[0].count * 4)
		sl++;
	chart = ft_mapnew(sl, sl);
	chart_dots(&chart, sl);
	while (chart_fill(&chart, sl, all, 0) == 0)
	{
		ft_mapdel(&chart, sl);
		sl++;
		chart = ft_mapnew(sl, sl);
		chart_dots(&chart, sl);
	}
	ft_mapput(chart, sl, sl);
	ft_mapdel(&chart, sl);
}

static void	all_clean(t_map **all_a, int count)
{
	int		i;

	i = -1;
	while (++i < count)
		ft_mapdel(&(*all_a)[i].map, 4);
	free(*all_a);
	all_a = NULL;
}

int			main(int ac, char **av)
{
	int		fd;
	int		count;
	t_map	*all;

	if (ac != 2)
		ft_putstr("usage: fillit input_file\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		count = check_all(fd);
		close(fd);
		if (count == 0)
			ft_putstr("error\n");
		else
		{
			fd = open(av[1], O_RDONLY);
			all = store_all(fd, count);
			all_put(all);
			all_clean(&all, count);
		}
	}
	return (0);
}
