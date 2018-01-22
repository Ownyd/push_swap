/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:41:39 by tlux              #+#    #+#             */
/*   Updated: 2018/01/22 23:26:24 by tlux             ###   ########.fr       */
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
	printf("DEBUT REFRAG\n");
	get_length(a, b, *lena, *lenb);
	getchar();
	nxtpivot = get_next_pivot(a, *lena, 'a');
	pivot = a[*lena - nxtpivot + get_median(ft_int_tab_dup(a, *lena - get_next_pivot(a, *lena, 'a'), *lena), get_next_pivot(a, *lena, 'a'))];
	store_pivot(&pivot, "add");
	printf("next pivot :%d\npivot frag :%d\n",nxtpivot,pivot);
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
	get_length(a, b, *lena, *lenb);
	getchar();
	}
	i = 0;
	while(i < decale)
	{
		rr(a, *lena, 1);
			if (a[*lena - 1] == pivot)
			{
				printf("pushing pivot\n pivot :%d\nlenb :%d",pivot ,*lenb);
				pb(a, b, &(*lena), &(*lenb));
				printf("pivot pushed\npivot :%d\nlenb :%d",pivot, *lenb);
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
	printf("lenb :%d\n",*lenb);
	printf("push :%d\n",push);
	get_length(a, b, *lena, *lenb);
	getchar();
}
void frag(int *a, int *b, int *lena, int *lenb, int *instructions)
{
	int nxtpivot;
	int pivot;
	int i;
	int decale;
	int push;
	i = 0;
	printf("DEBUT FRAG\n");
	get_length(a, b, *lena, *lenb);
	getchar();
	nxtpivot = get_next_pivot(a, *lena, 'a');
	pivot = a[*lena - nxtpivot + get_median(ft_int_tab_dup(a, *lena - get_next_pivot(a, *lena, 'a'), *lena), get_next_pivot(a, *lena, 'a'))];
	store_pivot(&pivot, "add");
	printf("next pivot :%d\npivot frag :%d\n",nxtpivot,pivot);
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
	get_length(a, b, *lena, *lenb);
	getchar();
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
	get_length(a, b, *lena, *lenb);
	getchar();
	}
	i = 0;
	printf("boucle");
	get_length(a, b, *lena, *lenb);
	getchar();
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
		printf("stack pa %d\n",i);
		pa(a, b, &(*lena), &(*lenb));
	if(get_next_pivot(a, *lena, 'a') == 2)
		s(a, *lena);
			(*instructions)++;
			i++;
	get_length(a, b, *lena, *lenb);
	getchar();
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
	printf("Decoupage A fini");
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
	printf("Dessus de B evacue");
	//printf("Length to next pivot :%d\n",get_next_pivot(b, lenb, 'b'));
	int tmp;
	int i;
	while (lenb != 0)
	{
		while (lenb != 0 && (store_pivot(&b[lenb - 1], "read") == 1 ||
					(lenb - 1 - get_place(b, lenb, b[lenb - 1])) == lenb - 1))
		{
			printf("0");
			pa(a, b, &lena, &lenb);
			instructions++;
	get_length(a, b, lena, lenb);
	getchar();
		}
		if (get_next_pivot(b, lenb, 'b') == 2)
		{
			s(b, lenb);
			pa (a, b, &lena, &lenb);
			pa (a, b, &lena, &lenb);
			instructions += 3;
	get_length(a, b, lena, lenb);
	getchar();
		}
		if (lenb == 0)
			break;
		tmp = get_next_pivot(b, lenb, 'b');
		pivot = b[lenb - get_next_pivot(b, lenb, 'b') + get_median(ft_int_tab_dup(b, lenb - get_next_pivot(b, lenb, 'b'), lenb), get_next_pivot(b, lenb, 'b'))];
		//	pivot = b[lenb - get_next_pivot(b, lenb, 'b') + get_median(b, lenb)];
		//		get_length(NULL ,ft_int_tab_dup(b, lenb - get_next_pivot(b, lenb, 'b'), lenb),0, get_next_pivot(b, lenb, 'b'));
		store_pivot(&pivot, "add");
		printf("NOUVEAU PIVOT :%d\n", pivot);
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
	get_length(a, b, lena, lenb);
	getchar();
		}
		tmp = pivot;
				printf("PIVOT av frag :%d\n",tmp);
		//	ICI ON DOIT TRAITER CE QU'ON VIENT DE METTRE DANS A
	while(get_next_pivot(a, lena, 'a') >= 3)
			frag(a, b, &lena, &lenb, &instructions);
				printf("PIVOT ap frag:%d\n",tmp);
		pivot = tmp;
	printf("NON-FRAG decale :%d",decale);
		while (decale > 0 && get_next_pivot(b, lenb, 'b') != lenb)
		{
			printf("%d\n",decale);
	get_length(a, b, lena, lenb);
	getchar();
				instructions++;
				rr(b, lenb, 1);
				decale--;
				printf("PIVOT :%d\n",pivot);
			if (b[lenb - 1] == pivot)
			{
				pa(a, b, &lena, &lenb);
				instructions++;
			}
		}
	}
	get_length(a, b, lena, lenb);
	getchar();
	printf("INSTRUCTIONS :%d",instructions);
}
