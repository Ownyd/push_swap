/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:05:44 by tlux              #+#    #+#             */
/*   Updated: 2018/01/20 19:08:16 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void quick_sort(int *a, int lena)
{
	int *b;
	int lenb;
	int pivot;

	b = (int *)malloc(sizeof(*b) * (lena));
	lenb = 0;
	pivot = a[get_median(a, lena)];
	store_pivot(&pivot, "add");
	printf("%d",store_pivot(&pivot, "read"));
//	pivot = a[lena - 1 - get_nb_sorted(a, lena) + get_median(ft_int_tab_dup(a, lena - 1 - get_nb_sorted(a, lena), lena - 1), lena)];
//	On doit stocker qqpart nos pivots pour partitionner le tableau et definir des sous-medianes (getplace ne marche pas car le tableau n'est pas partitionne)
//	TO DO : colorer les parties partitionnes mais pas triees sur le visu 
//	TO DO : colorer les pivots de maniere differente
	get_length(a, b, lena, lenb);
	printf("\nPivot a :%d\n", pivot);
	while (a[get_extrems(a, lena, 0)] != pivot)
	{
		get_length(a, b, lena, lenb);
		if (a[lena - 1] < pivot)
			pb(a, b, &lena, &lenb);
		if (a[lena - 1] >= pivot)
			r(a, lena, 1);
	}
	while (a[lena - 1] != pivot)
		r(a, lena, 1);
	get_length(a, b, lena, lenb);
	pivot = b[get_median(b, lenb)];
	store_pivot(&pivot, "add");
	printf("\nPivot b :%d\n", pivot);
	getchar();
	/*
	 *	Choix du pivot dans b
	 *	On remet les elements  > du pivot
	 *	Puis pivot
	 *	Puis les elements < pivot
	 *	? : Boucler le pivot dans b ?
	 */
	while (lenb != 0)
	{
		get_length(a, b, lena, lenb);
		if (b[lenb - 1] > pivot && b[lenb - 1] < b[lenb - 2])
			s(b, lenb);
		if (b[lenb - 1] > pivot)
		{
			pa(a, b, &lena, &lenb);
			if (a[lena - 1] > a[lena - 2])
				s(a, lena);
		}
		if (pivot == b[get_extrems(b, lenb, 1)])
		{
			while (b[lenb - 1] != pivot)
				r(b, lenb, 1);
			pa(a, b, &lena, &lenb);
		}
		if (b[lenb - 1] <= pivot && pivot != b[get_extrems(b,lenb,0 )])
			r(b, lenb, 1);
		if (b[get_extrems(b, lenb, 1)] < pivot)
		{
			pa(a, b, &lena, &lenb);
			if (a[lena - 1] > a[lena - 2])
				s(a, lena);
		}
	}
	//partitionner le tableau
	//...
	//pivot
	//...
	//pivot
	//...
	//pivot
	//...
	//TO DO : rajouter un pivot
	//? : possibilite de le faire pendant le premier pivot avec des rr / ss ?
	//ensuite on envoie en recursive pour gerer partitions
	get_length(a, b, lena, lenb);
}
