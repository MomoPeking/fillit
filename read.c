/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:56:24 by qdang             #+#    #+#             */
/*   Updated: 2019/10/28 21:28:48 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	check_connection(char *buff)
{
	int		i;
	int		idx;

	i = 0;
	idx = 0;
	while (i <= 18)
	{
		while (i <= 18 && buff[i] != '#')
			i++;
		if (i + 1 <= 18 && buff[i + 1] == '#')
			idx++;
		if (i - 1 >= 0 && buff[i - 1] == '#')
			idx++;
		if (i + 5 <= 18 && buff[i + 5] == '#')
			idx++;
		if (i - 5 >= 0 && buff[i - 5] == '#')
			idx++;
		i++;
	}
	if (idx == 8 || idx == 6)
		return (1);
	else
		return (0);
}

static int	check_map(char *buff)
{
	int		ns;
	int		i;
	int		j;

	ns = 0;
	i = 0;
	while (i <= 18)
	{
		j = i + 3;
		while (i <= j)
		{
			if (buff[i] != '.' && buff[i] != '#')
				return (0);
			if (buff[i] == '#')
				ns++;
			i++;
		}
		i++;
	}
	return (ns);
}

static int	check_tetris(char *buff, int rt)
{
	if (rt != 19 && rt != 21)
		return (0);
	if (rt == 21)
		if (buff[19] != '\n' || buff[20] != '\n')
			return (0);
	if (buff[4] != '\n' || buff[9] != '\n' || buff[14] != '\n')
		return (0);
	if (check_map(buff) != 4)
		return (0);
	if (check_connection(buff) == 0)
		return (0);
	return (1);
}

int			check_all(int fd)
{
	int		rt;
	char	buff[21];
	int		count;

	count = 0;
	if (fd < 0 || read(fd, buff, 0) < 0)
		return (0);
	while ((rt = read(fd, buff, 21)) > 0)
	{
		count++;
		if (check_tetris(buff, rt) == 0)
			return (0);
	}
	if (count < 1 || count > 26)
		return (0);
	return (count);
}
