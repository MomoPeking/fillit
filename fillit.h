/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 07:36:16 by qdang             #+#    #+#             */
/*   Updated: 2019/11/07 15:08:08 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;
typedef struct	s_map
{
	char	**map;
	int		count;
	t_point	start;
	t_point	size;
}				t_map;
int				check_all(int fd);
t_map			*store_all(int fd, int count);
int				chart_fill(char ***chart_a, int sl, t_map *all, int nb);
void			chart_dots(char ***chart_a, int size);

#endif
