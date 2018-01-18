/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extrems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:58:46 by tlux              #+#    #+#             */
/*   Updated: 2018/01/18 20:04:18 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/*
 *	To get highest -> choice = 1
 *	To get lowest -> choice = 0
 */

int get_extrems(int *tab, int lentab, int choice)
{
	int i;
	int highest;
	int ret;
	ret = 0;
	if (lentab == 0)
		return (-1);
	highest = tab[0];
	i = 0;
	while (i < lentab)
	{
		if (choice == 1)
			if (tab[i] >= highest)
			{
				highest = tab[i];
				ret = i;
			}
		if (choice == 0)
			if (tab[i] <= highest)
			{
				highest = tab[i];
				ret = i;
			}
		i++;
	}
	return(ret);
}
