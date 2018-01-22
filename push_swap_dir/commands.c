/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlux <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:50:16 by tlux              #+#    #+#             */
/*   Updated: 2018/01/22 22:04:23 by tlux             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void s(int *tab, int lentab)
{
	ft_swap(&(tab[lentab - 1]), &(tab[lentab - 2]));
		printf("s\n");
}
void r(int *tab, int lentab, int nb)
{
	int i;

	while (nb > 0)
	{
		i = lentab;
		while (--i > 0)
			ft_swap(&(tab[i]), &(tab[i - 1]));
		nb--;
		printf("r\n");
	}
}

void pa(int *a, int *b, int *lena, int *lenb)
{
	a[*lena] = b[*lenb - 1];
	(*lena)++;
	(*lenb)--;
		printf("pa\n");
}

void pb(int *a, int *b, int *lena, int *lenb)
{
	b[*lenb] = a[*lena - 1];
	(*lenb)++;
	(*lena)--;
		printf("pb\n");
}

void rr(int *tab, int lentab, int nb)
{
	int i;

	while (nb > 0)
	{
		printf("rr\n");
		i = -1;
		while (++i < lentab - 1)
			ft_swap(&(tab[i]), &(tab[i + 1]));
		nb--;
	}
}
