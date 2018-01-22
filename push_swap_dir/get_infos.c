/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extrems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:58:46 by tlux              #+#    #+#             */
/*   Updated: 2018/01/22 22:06:40 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/*
 *	To get highest -> choice = 1
 *	To get lowest -> choice = 0
 */

int get_next_pivot(int *tab, int lentab, char list)
{
	int i;
	int length;;
	length = 0;
	i = lentab - 1;
	while (store_pivot(&tab[i], "read") == 0 && i >= 0)
	{
		length++;
		i--;
	}
	if (list == 'a' && length != lentab)
	while (i + 1  == get_place(tab, lentab, tab[i + 1]))
	{
		length--;
		i++;
	}
	if (list == 'b' && length != lentab)
	while (i + 1  == lentab - 1 - get_place(tab, lentab, tab[i + 1]))
	{
		length--;
		i++;
	}
	return (length);
}

int get_place(int *tab, int lentab, int number)
{
	int i;
	int place;

	place = lentab - 1;
	i = 0;
	while (i < lentab)
	{
		if (tab[i] < number)
			place--;
		i++;
	}
	return (place);
}

int get_median(int *tab, int lentab)
{
	int i;
	int medianindex;

	
	if (lentab == 1)
		return(0);
	i = 0;
	medianindex = get_extrems(tab, lentab, 0);
//	printf("start medianindex :%d\n",medianindex);
	while(i < lentab / 2)
	{
		medianindex = get_next(tab, lentab, medianindex);
		i++;
	}
//	printf("mediandinex :%d\npivot :%d\n",medianindex, tab[medianindex]);
	return (medianindex);
}

int get_next(int *tab, int lentab, int indexnumber)
{
	int ret; //retourne la place du next
	int i;
	int next;
	int indexnext;

	indexnext = -1;
	next = tab[get_extrems(tab, lentab, 1)];
	i = 0;
	while (i < lentab)
	{
		if (tab[i] < next && tab[i] > tab[indexnumber] && i != indexnumber)
		{
			ret = i;
			next = tab[i];
			indexnext = i;
		}
		i++;
	}
	return(ret);
}

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
