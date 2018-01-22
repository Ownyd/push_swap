/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:36:37 by tlux              #+#    #+#             */
/*   Updated: 2018/01/19 19:22:03 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

void rotate_push(int *a, int lena)
{
	int *b;
	int lenb;
	int instructions = 0;

	b = (int *)malloc(sizeof(*b) * (lena));
	lenb = 0;
	while (lena != 0 && !(ft_issort(a, lena) == 1))
	{
		if (ft_issort(a, lena) == 0 && lena == 2)
		{
	//	getchar();
	//	get_length(a, b, lena, lenb);
			instructions++;
			s(a, lena);
		}
		else if ((lena - 1 - get_extrems(a, lena, 0) <= get_extrems(a, lena, 0) + 1))
		{
	//	getchar();
	//	get_length(a, b, lena, lenb);
			instructions+= (lena - get_extrems(a, lena, 0) - 1);
			r(a, lena, lena - 1 - get_extrems(a, lena , 0));
		}
		else
		{
	//	getchar();
	//	get_length(a, b, lena, lenb);
			instructions+= (get_extrems(a, lena, 0) + 1);
			rr(a, lena, get_extrems(a, lena, 0) + 1);
		}
		if (ft_issort(a, lena) == 0)
		{
	//	getchar();
	//	get_length(a, b, lena, lenb);
			pb(a, b, &lena, &lenb);
			instructions++;
		}
//		get_length(a, b, lena, lenb);
//		printf("Index 2nd :%d\n", get_next(a, lena, get_extrems(a, lena, 0)));
//		printf("2nd nombre :%d", a[get_next(a, lena, get_extrems(a, lena, 0))]);
	//printf("Instructions :%d\n",instructions);
	}
	while(lenb != 0)
	{
			instructions++;
		pa(a, b, &lena, &lenb);
	//	get_length(a, b, lena, lenb);
	//	getchar();
	}
		get_length(a, b, lena, lenb);
	printf("Instructions :%d\n",instructions);
}

