/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:41:39 by tlux              #+#    #+#             */
/*   Updated: 2018/01/22 23:38:39 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void refrag(int *a, int *b, int *lena, int *lenb, int *instructions)
{
	int nxtpivot;
	int pivot;
	int decale;
	int push;
	int i;
	i = 0;
	nxtpivot = get_next_pivot(a, *lena, 'a');
	pivot = a[*lena - nxtpivot + get_median(ft_int_tab_dup(a, *lena - get_next_pivot(a, *lena, 'a'), *lena), get_next_pivot(a, *lena, 'a'))];
	store_pivot(&pivot, "add");
	decale = 0;
	push = 0;
	while (i < nxtpivot)
	{
		if(a[*lena - 1] < pivot)
		{
			(*instructions)++;
			pb(a, b, &(*lena), &(*lenb));
			push++;
		}
		else if (a[*lena - 1] >= pivot)
		{
			r(a, *lena, 1);
			(*instructions)++;
			decale++;
		}
		i++;
	}
	i = 0;
	while(i < decale)
	{
		rr(a, *lena, 1);
			if (a[*lena - 1] == pivot)
			{
				pb(a, b, &(*lena), &(*lenb));
			(*instructions)++;
				push++;
			}
		(*instructions)++;
		i++;
	}
		if(get_next_pivot(a, *lena, 'a') == 2)
			s(a, *lena);
		else
	while(get_next_pivot(a, *lena, 'a') >= 3)
	{
		refrag (a, b, lena, lenb, instructions);
	}
	while(push > 0)
	{
		pa(a, b, &(*lena), &(*lenb));
		if(get_next_pivot(a, *lena, 'a') == 2)
			s(a, *lena);
		instructions++;
		push--;
	}
}
void frag(int *a, int *b, int *lena, int *lenb, int *instructions)
{
	int nxtpivot;
	int pivot;
	int i;
	int decale;
	int push;
	i = 0;
	nxtpivot = get_next_pivot(a, *lena, 'a');
	pivot = a[*lena - nxtpivot + get_median(ft_int_tab_dup(a, *lena - get_next_pivot(a, *lena, 'a'), *lena), get_next_pivot(a, *lena, 'a'))];
	store_pivot(&pivot, "add");
	decale = 0;
	push = 0;
	while (i < nxtpivot)
	{
		if(a[*lena - 1] < pivot)
		{
			(*instructions)++;
			pb(a, b, lena, lenb);
			push++;
		}
		else if (a[*lena - 1] >= pivot)
		{
			r(a, *lena, 1);
			(*instructions)++;
			decale++;
		}
		i++;
	}
	i = 0;
	while(i < decale)
	{
		rr(a, *lena, 1);
			if (a[*lena - 1] == pivot && instructions++)
			{
				pb(a, b, lena, lenb);
			(*instructions)++;
				push++;
			}
		(*instructions)++;
		i++;
	}
	i = 0;
	if(get_next_pivot(a, *lena, 'a') == 2)
		s(a, *lena);
	else
	while(get_next_pivot(a, *lena, 'a') >= 3)
	{
		refrag (a, b, lena, lenb, instructions);
	}

	while (i > 0)
	{
		pa(a, b, &(*lena), &(*lenb));
		(*instructions)++;
	if(get_next_pivot(a, *lena, 'a') == 2)
		s(a, *lena);
		i--;
	}
	i = 0;
	while (i < push)
	{
		pa(a, b, &(*lena), &(*lenb));
	if(get_next_pivot(a, *lena, 'a') == 2)
		s(a, *lena);
			(*instructions)++;
			i++;
	}
}

void quick_sort_multi_pivot(int *a, int lena)
{
	int *b;
	int lenb;
	int pivot;
	int instructions;
	int decale;
	decale = 0;
	instructions = 0;
	b = (int *)malloc(sizeof(*b) * (lena));
	lenb = 0;
	while (lena > 2)
	{
		pivot = a[get_median(a, lena)];
		store_pivot(&pivot, "add");
		while (pivot != a[get_extrems(a, lena, 0)] || a[lena - 1] != pivot)
		{
			if (a[lena - 1] < pivot && instructions++)
				pb(a, b, &lena, &lenb);
			if (a[lena - 1] > pivot || (a[lena - 1] == pivot &&
						pivot != a[get_extrems(a, lena, 0)]))
			{
				instructions++;
				r(a, lena, 1); //Si pivot mal place, optimiser ra/rra
			}
		}
	}
	while (get_next_pivot(b, lenb, 'b') <= 2 && lenb != 0)
	{
		while (store_pivot(&b[lenb - 1], "read") == 1 ||
				(lenb - 1 - get_place(b, lenb, b[lenb - 1])) == lenb - 1)
		{
			pa(a, b, &lena, &lenb);
			instructions++;
	if(get_next_pivot(a, lena, 'a') == 2)
		s(a, lena);
		}
		if (get_next_pivot(b, lenb, 'b') == 2)
		{
			s(b, lenb);
			pa (a, b, &lena, &lenb);
			pa (a, b, &lena, &lenb);
			instructions += 3;
		}
	}
	int tmp;
	int i;
	while (lenb != 0)
	{
		while (lenb != 0 && (store_pivot(&b[lenb - 1], "read") == 1 ||
					(lenb - 1 - get_place(b, lenb, b[lenb - 1])) == lenb - 1))
		{
			pa(a, b, &lena, &lenb);
			instructions++;
		}
		if (get_next_pivot(b, lenb, 'b') == 2)
		{
			s(b, lenb);
			pa (a, b, &lena, &lenb);
			pa (a, b, &lena, &lenb);
			instructions += 3;
		}
		if (lenb == 0)
			break;
		tmp = get_next_pivot(b, lenb, 'b');
		pivot = b[lenb - get_next_pivot(b, lenb, 'b') + get_median(ft_int_tab_dup(b, lenb - get_next_pivot(b, lenb, 'b'), lenb), get_next_pivot(b, lenb, 'b'))];
		store_pivot(&pivot, "add");
		i = 0;
		while (i < tmp)
		{
			if(b[lenb - 1] > pivot)
			{
				instructions++;
				pa(a, b, &lena, &lenb);
				decale--;
				if(get_next_pivot(a, lena ,'a') == 2)
				{
					s(a, lena);
					instructions++;
				}
			}
			else
			{
				r(b, lenb, 1);
				instructions++;
			}
			decale++;
			i++;
		}
		tmp = pivot;
	while(get_next_pivot(a, lena, 'a') >= 3)
			frag(a, b, &lena, &lenb, &instructions);
		pivot = tmp;
		while (decale > 0 && get_next_pivot(b, lenb, 'b') != lenb)
		{
				instructions++;
				rr(b, lenb, 1);
				decale--;
			if (b[lenb - 1] == pivot)
			{
				pa(a, b, &lena, &lenb);
				instructions++;
			}
		}
	}
	if (ft_issort(a, lena))
		printf("OK");
}
