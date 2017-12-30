/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klouer <klouer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 22:26:16 by klouer            #+#    #+#             */
/*   Updated: 2017/12/30 02:50:25 by klouer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** -c : pre-colored mode --now packed
** -cr : packed random color mode
** -cm : macro colored mode
** -cfr : full random color mode
*/

int		ft_argparse(char **av)
{
	if (!ft_strncmp(av[1], "-cr", 3))
		return (2);
	else if (!ft_strncmp(av[1], "-cm", 3))
		return (3);
	else if (!ft_strncmp(av[1], "-cfr", 4))
		return (4);
	else if (!ft_strncmp(av[1], "-c", 2))
		return (1);
	return (0);
}

void	ft_argmode(int mode,t_res *res, int x, int y, int *rt)
{
//	int *rt;
	static int ran = 0;

//	if (ran == 0)
//		rt = 0;
	if (mode == 3)
		ft_color_map1(res, x, y);
	else if (mode == 2)
	{
//		if (ran == 0)
//			rt = ft_randomtab(27, 15, 240);
		ft_aleasortedcolor(res, x, y, rt);
		ran = 1;
	}
	else if (mode == 4)
		ft_aleacolor(res, x, y);
	else if (mode == 1)
	{
//		if (ran == 0)
//			rt = ft_genpremadecolortab();
		ft_aleasortedcolor(res, x, y, rt);
		ran = 1;
	}
}
