/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:56:56 by qdang             #+#    #+#             */
/*   Updated: 2019/11/06 15:16:19 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
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
			chart_output(all, count);
		}
	}
	return (0);
}
